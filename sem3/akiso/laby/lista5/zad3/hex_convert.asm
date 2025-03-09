section .data
    num_to_print dd 123456     ; liczba do wydruku w hex, można zmienić wg uznania
    hex_buffer db 11 dup(0)    ; bufor na wynik hex (0x + 8 cyfr + terminator)
    prefix db "0x",0           ; prefiks 0x (opcjonalnie)
    newline db 10,0            ; znak nowej linii
    ; Komunikat powitalny (opcjonalny)
    msg db "Wartosc hex: ",0
    len_msg equ $ - msg

section .text
    global _start

_start:
    ; Wczytujemy liczbę do eax
    mov eax, [num_to_print]

    ; Konwertujemy eax do zapisu szesnastkowego w buforze hex_buffer
    push eax
    push hex_buffer
    call int_to_hex
    add esp,8

    ; Wypisz opcjonalny komunikat
    push len_msg-1   ; bez \0
    push msg
    call print_str
    add esp,8

    ; Wypisz liczbę w hex
    push dword 0xFFFFFFFF ; placeholder długości (obliczymy za chwile)
    push hex_buffer
    call length_string
    ; eax = długość
    mov edx, eax

    push edx
    push hex_buffer
    call print_str
    add esp,8

    ; Wypisz nową linię
    push 1      ; długość '\n'
    push newline
    call print_str
    add esp,8

    ; Wyjście z programu
    push 0
    call exit

; print_str:
; Parametry na stosie:
;   [esp] = adres stringa
;   [esp+4] = długość stringa
; Działanie: wywołuje write(1, string, length)
print_str:
    push ebp
    mov ebp, esp
    mov eax,4       ; syscall write
    mov ebx,1       ; stdout
    mov ecx,[ebp+8] ; adres stringa
    mov edx,[ebp+12]; długość
    int 0x80
    pop ebp
    ret

; exit:
; Parametry:
;   [esp] = kod wyjścia
; Działanie: wywołuje exit(kod)
exit:
    push ebp
    mov ebp, esp
    mov eax,1   ; syscall exit
    mov ebx,[ebp+8]
    int 0x80
    pop ebp
    ret

; length_string:
; Parametry:
;   [esp] = adres zero-terminated stringa
; Wynik w eax = długość (bez końcowego '\0')
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

; int_to_hex:
; Parametry na stosie:
;   [esp] = adres bufora (wystarczająco dużego)
;   [esp+4] = liczba (32-bit, w eax)
; Konwertuje liczbę na zapis szesnastkowy (bez prefiksu 0x).
; Rezultat: w buforze zapisane cyfry hex, a na końcu '\0'.
; Dla uproszczenia używamy tylko małych liter a-f.
int_to_hex:
    push ebp
    mov ebp, esp
    mov edi, [ebp+8]    ; adres bufora
    mov eax, [ebp+12]   ; liczba do konwersji

    ; Dodaj opcjonalny prefiks "0x"
    mov byte [edi],'0'
    mov byte [edi+1],'x'
    mov byte [edi+2],0
    add edi,2

    ; Jeśli liczba = 0, to wypiszemy po prostu "0" i zakończymy
    cmp eax,0
    jne .convert
    mov byte [edi],'0'
    mov byte [edi+1],0
    jmp .done

.convert:
    ; Przygotowujemy konwersję - zapis od końca
    ; Maksymalnie 8 cyfr dla 32-bit (0x + 8 cyfr + \0)
    push ebx
    mov ebx,16
    mov esi,edi
    add esi,8   ; wskaźnik na koniec potencjalnych cyfr
    mov byte [esi],0

.hex_loop:
    xor edx,edx
    div ebx       ; dzielimy eax przez 16, reszta w edx
    ; konwertuj edx do znaku hex
    cmp edx,10
    jl .digit_num
    add dl,'a'-10
    jmp .store
.digit_num:
    add dl,'0'
.store:
    dec esi
    mov [esi],dl
    cmp eax,0
    jne .hex_loop

    ; kopiujemy cyfry z [esi..] do [edi..]
    mov edi,[ebp+8]
    add edi,2  ; pomijamy 0x już zapisane
.copy_loop:
    mov al,[esi]
    mov [edi],al
    inc esi
    inc edi
    cmp al,0
    jne .copy_loop

    pop ebx

.done:
    pop ebp
    ret
