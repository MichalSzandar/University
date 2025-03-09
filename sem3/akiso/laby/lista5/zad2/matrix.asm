section .data
    ; Macierz 3x3 (9 liczb)
    matrix: dd 1, 2, 3, 4, 5, 6, 7, 8, 9

    msg_all db "Suma wszystkich elementow: ",0
    len_msg_all equ $ - msg_all   ; długość napisu z '\0'

    msg_diag db "Suma elementow na przekatnej glownej: ",0
    len_msg_diag equ $ - msg_diag

    newline db 10,0
    len_newline equ 1 ; tylko znak '\n'

    ; Bufory na skonwertowane liczby
    result_all_str db 12 dup(0)
    result_diag_str db 12 dup(0)


section .text
    global _start

_start:
    ; sumujemy wszystkie elementy
    mov esi, matrix
    mov ecx, 9
    xor eax, eax
sum_all_loop:
    mov edx, [esi]
    add eax, edx
    add esi, 4
    loop sum_all_loop
    ; teraz eax = suma wszystkich elementów
    push eax              ; wrzucamy na stos wynik do konwersji
    push result_all_str   ; adres bufora na stos
    call int_to_ascii
    add esp, 8

    mov ebx, eax  ; zapamiętamy sumę wszystkich elementów w ebx (opcjonalnie)

    ; sumujemy przekątną
    mov esi, matrix
    xor eax, eax

    ; a11
    mov edx, [esi]
    add eax, edx

    ; a22
    add esi, 16
    mov edx, [esi]
    add eax, edx

    ; a33
    add esi, 16
    mov edx, [esi]
    add eax, edx

    ; eax = suma przekątnej
    push eax
    push result_diag_str
    call int_to_ascii
    add esp, 8

    ; Wyświetlamy wyniki
    ; Wypisz msg_all
    push len_msg_all-1    ; bez \0
    push msg_all
    call print_str

    ; print_str oczekuje:
    ; [esp] = adres stringa
    ; [esp+4] = długość
    ; więc najpierw obliczymy długość:
    push result_all_str
    call length_string
    ; wynik w eax
    push eax
    push result_all_str
    call print_str
    add esp,8

    ; Nowa linia
    push len_newline
    push newline
    call print_str
    add esp,8

    ; Wypisz msg_diag
    push len_msg_diag-1    ; bez \0
    push msg_diag
    call print_str
    add esp,8

    ; Wypisz sumę przekątnej
    push result_diag_str
    call length_string
    push eax
    push result_diag_str
    call print_str
    add esp,8

    ; Nowa linia
    push len_newline
    push newline
    call print_str
    add esp,8

    ; Zakończ program
    push 0
    call exit


;---------------------------------------------
; Funkcje pomocnicze
;---------------------------------------------

; print_str:
; Parametry na stosie:
;   [esp] = adres stringa
;   [esp+4] = długość
; Wywołanie syscall write(1, string, length)
print_str:
    push ebp
    mov ebp, esp
    mov eax,4    ; sys_write
    mov ebx,1    ; stdout
    mov ecx,[ebp+8]  ; string address
    mov edx,[ebp+12] ; length
    int 0x80
    pop ebp
    ret

; exit:
; Parametry na stosie:
;   [esp] = kod wyjścia
exit:
    push ebp
    mov ebp, esp
    mov eax,1    ; sys_exit
    mov ebx,[ebp+8]
    int 0x80
    pop ebp
    ret

; int_to_ascii:
; Parametry na stosie:
;   [esp] = adres bufora (char*)
;   [esp+4] = liczba (int)
; Zamienia integer w [esp+4] na ASCII w buforze [esp].
; Działa tylko dla liczb >= 0.
int_to_ascii:
    push ebp
    mov ebp, esp
    mov edi, [ebp+8]    ; bufor
    mov eax, [ebp+12]   ; liczba

    cmp eax,0
    jne .convert
    mov byte [edi],'0'
    mov byte [edi+1],0
    jmp .done

.convert:
    ; obliczamy cyfry od końca
    mov ebx,10
    mov esi,edi
    add esi,11     ; wskaźnik na koniec bufora (max 11 cyfr + '\0')
    mov byte [esi],0

.loop_div:
    xor edx, edx
    div ebx      ; dzielimy eax przez 10
    add dl,'0'   ; konwersja cyfry na znak
    dec esi
    mov [esi],dl
    cmp eax,0
    jne .loop_div

    ; kopiujemy wynik od esi do edi
    mov edi,[ebp+8]
.copy_loop:
    mov al,[esi]
    mov [edi],al
    inc edi
    inc esi
    cmp al,0
    jne .copy_loop

.done:
    pop ebp
    ret

; length_string:
; Parametry:
;   [esp] = adres zero-terminated stringa
; Wynik w eax = długość (bez końcowego 0)
length_string:
    push ebp
    mov ebp, esp
    mov edi, [ebp+8]
    xor ecx, ecx
.len_loop:
    mov al, [edi+ecx]
    cmp al,0
    je .len_done
    inc ecx
    jmp .len_loop
.len_done:
    mov eax,ecx
    pop ebp
    ret
