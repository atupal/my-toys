
print_string:
  pusha
  mov ah, 0x0e

print_string_loop:
  mov al, [bx]
  int 0x10

  cmp al, 0
  je print_string_done

  add bx, 1

  jmp print_string_loop  ; loop around to print the next char.

print_string_done:
  popa
  ret  ; Return from the function
