mov ah, 0x02  ; BIOS read sector function

mov dl, 0  ; Read drive 0 (i.e. first floppy drive)
mov ch, 3  ; Select cylinder 3
mov dh, 1  ; Select the track on 2nd side of floppy 
           ; disk, since this count has a base of 0
mov cl, 4  ; Select the 4th Sector on the track,
           ; not the 5th, since this has a base of 1.
mov al, 5  ; Read 5 sectors from the start point

; Lastly, set the address that we'd like BIOS to read the 
; sectors to, which BIOS expects to find in ES:BX
; (i.e. segment ES with offset BX).
mov bx, 0xa00  ; Indirectly set ES to 0xa000
mov es, bx
mov bx, 0x1234 ; Set BX to 0x1234
; In our case, data will be read to 0xa000:01234, which the
; CPU will translate to physical address 0xa1234

int 0x13  ; Now issue the BIOS interrupt to do the actual read.

;
; Padding and magic BIOS number.
;

times 510-($-$$) db 0

dw 0xaa55
