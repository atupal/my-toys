mov ah, 0x0e  ; int 10/ah = 0eh -> scrolling teletype BIOS routine

; first attempt
mov al, 10
int 0x10
mov al, '1'
int 0x10
mov al, 10
int 0x10

mov al, the_secret
int 0x10

; second attempt
mov al, 10
int 0x10
mov al, '2'
int 0x10
mov al, 10
int 0x10

mov al, [the_secret]
int 0x10

;third attempt
mov al, 10
int 0x10
mov al, '3'
int 0x10
mov al, 10
int 0x10

mov bx, the_secret
add bx, 0x7c00
mov al, [bx]
int 0x10

; fourth attempt
mov al, 10
int 0x10
mov al, '4'
int 0x10
mov al, 10
int 0x10

mov al, [0x7c4d]
int 0x10

;loop:
  ;jmp loop
jmp $  ; jump to the current address (i.e. forever).

the_secret:
  db "X"
;
; Padding and magic BIOS number.
;
times 510-($-$$) db 0

dw 0xaa55
