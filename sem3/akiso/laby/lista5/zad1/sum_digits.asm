section .data
    prompt_msg db "Podaj liczbe: ", 0
    newline db 10, 0

section .bss
    buffer resb 128     ; bufor na wczytany ciąg
    result_str resb 12  ; bufor na wynik

section .text
    global _start

_start:
    ; --- Wypisanie komunikatu ---
    mov eax, 4            ; sys_write
    mov ebx, 1            ; stdout
    mov ecx, prompt_msg
    mov edx, 14           ; długość tekstu "Podaj liczbe: "
    int 0x80

    ; --- Wczytanie liczby ze standardowego wejścia ---
    mov eax, 3           ; sys_read
    mov ebx, 0           ; stdin
    mov ecx, buffer
    mov edx, 128
    int 0x80

    ; EAX zawiera liczbę bajtów wczytanych
    ; Przetwarzamy wczytane dane, obliczamy sumę cyfr

    xor edi, edi   ; edi = 0 (sumowanie cyfr)
    mov esi, buffer

parse_loop:
    cmp byte [esi], 0x0A  ; sprawdź czy znak to '\n'
    je end_parse
    cmp byte [esi], 0     ; sprawdź czy koniec
    je end_parse

    cmp byte [esi], '0'
    jb not_digit
    cmp byte [esi], '9'
    ja not_digit

    ; Dodaj cyfrę do sumy
    mov ebx, [esi]
    and ebx, 0xFF
    sub ebx, '0'
    add edi, ebx

not_digit:
    inc esi
    jmp parse_loop

end_parse:

    ; Teraz w EDI mamy sumę cyfr
    ; Konwersja liczby całkowitej (w EDI) na ASCII
    mov eax, edi
    mov ebx, 10
    lea esi, [result_str + 11]
    mov byte [esi], 0
    dec esi

convert_loop:
    xor edx, edx
    div ebx            ; EAX/10, reszta w EDX
    add dl, '0'
    mov [esi], dl
    dec esi
    cmp eax, 0
    jne convert_loop
    inc esi

    ; Wypisanie wyniku
    mov eax, 4         ; sys_write
    mov ebx, 1         ; stdout
    mov ecx, esi
    ; Oblicz długość
    mov edx, 0
length_calc:
    cmp byte [ecx+edx], 0
    je print_out
    inc edx
    jmp length_calc

print_out:
    int 0x80

    ; Wypisanie nowej linii
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Zakończenie programu
    mov eax, 1   ; sys_exit
    xor ebx, ebx
    int 0x80
