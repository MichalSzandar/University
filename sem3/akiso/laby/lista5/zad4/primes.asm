section .data
    newline db 0x0A, 0
    ; Bufor na konwersję liczby do ASCII
    ; Zapas na 6 cyfr (max 99999) plus znak końca linii
    num_buf db "000000",0

section .bss
    ; brak bss

section .text
global _start

; Funkcja: print_string
; Wejście:
;   EAX - adres stringu zakończonego znakiem 0x00 (C-string)
; Działanie:
;   Wypisuje dany ciąg znaków na stdout
print_string:
    pushad
    ; EAX zawiera adres, musimy obliczyć długość
    push eax            ; zachowaj adres
    mov edx, 0
    mov ebx, eax
.count_len:
    cmp byte [ebx], 0
    je .len_done
    inc ebx
    inc edx
    jmp .count_len
.len_done:
    ; Teraz EAX ma oryginalny adres (na stosie),
    ; EDX - długość, przeniesiemy adres do ECX
    pop eax
    mov ecx, eax
    mov ebx, 1          ; stdout
    mov eax, 4          ; sys_write
    int 0x80
    popad
    ret

; Funkcja: print_newline
; Wypisuje znak nowej linii
print_newline:
    pushad
    mov eax, newline
    call print_string
    popad
    ret

; Funkcja: print_number
; Wejście:
;   EAX - liczba do wypisania (0 <= EAX <= 99999)
; Działanie:
;   Konwertuje liczbę na ASCII i wypisuje
print_number:
    pushad
    mov edi, num_buf+5  ; Ustaw EDI na koniec bufora (ostatnia cyfra)
    mov ecx, 5          ; Ilość cyfr do wygenerowania
    mov ebx, 10

.convert_loop:
    xor edx, edx
    div ebx              ; EAX/10, EDX = reszta
    add dl, '0'
    mov [edi], dl
    dec edi
    loop .convert_loop

    ; Teraz w buforze mamy może wiodące zera
    ; Znajdź pierwszy niezerowy znak lub ostatni zero i od tego miejsca wypisz
    mov edi, num_buf
.skip_leading:
    cmp byte [edi], '0'
    jne .no_lead_zero
    cmp edi, num_buf+4
    je .no_lead_zero     ; jeśli to ostatni znak, to liczba to 0
    inc edi
    jmp .skip_leading

.no_lead_zero:
    mov eax, edi   ; Umieszczamy adres początka liczb w EAX
    call print_string
    popad
    ret

; Funkcja: is_prime
; Wejście:
;   EAX - liczba do sprawdzenia
; Wyjście:
;   EAX = 1 jeśli pierwsza, 0 jeśli nie
; Założenia:
;   0 i 1 nie są pierwsze.
;   Dla liczby 2 jest pierwsza.
; Testowanie dzielenia od 2 do sqrt(n).
is_prime:
    pushad
    cmp eax, 2
    jl .not_prime
    cmp eax, 2
    je .prime
    mov ebx, eax  ; ebx = n
    mov ecx, 2

.test_loop:
    ; sprawdzamy czy ecx * ecx <= ebx
    mov edx, ecx
    imul edx, edx
    cmp edx, ebx
    jg .end_test    ; jeśli ecx^2 > n, kończymy test, n jest pierwsza
    ; sprawdzamy czy n % ecx == 0
    mov eax, ebx
    xor edx, edx
    div ecx
    cmp edx, 0
    je .not_prime   ; podzielna, nie pierwsza

    inc ecx
    jmp .test_loop

.end_test:
    ; Tu jeśli nie było dzielnika, liczba jest pierwsza
    jmp .prime

.prime:
    popad
    mov eax, 1
    ret

.not_prime:
    popad
    mov eax, 0
    ret

_start:
    ; wypisz wszystkie pierwsze od 2 do 100000
    mov esi, 2          ; iterator
    mov edi, 100000

.main_loop:
    cmp esi, edi
    jg .done
    mov eax, esi
    call is_prime
    cmp eax, 1
    jne .next
    ; jeśli pierwsza, wydrukuj
    mov eax, esi
    call print_number
    call print_newline

.next:
    inc esi
    jmp .main_loop

.done:
    ; Wyjście z programu
    mov eax,1   ; sys_exit
    xor ebx, ebx
    int 0x80
