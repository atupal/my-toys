#include "drivers/screen.h"
#include "drivers/keyboard.h"
#include "kernel/kernel.h"

void main() {
  // Create a pointer to a char, and point it to the first text cell of 
  // video memory (i.e. the top-left of the screen)
  char *video_memory = (char*) 0xb8000;
  // At the address pointed to by video_memory, store the character 'X'
  // (i.e. display 'X' in the top-left of the screen)
  int s[100];
  *video_memory = 'X';
  /*
  s[13] = 233;
  *(video_memory+1) = 'H';
  *(video_memory+3) = 'e';
  *(video_memory+5) = 'l';
  *(video_memory+7) = 'l';
  *(video_memory+9) = 'o';
  *(video_memory+11) = '!';
  *(video_memory+13) = 'W';
  *(video_memory+15) = 'o';
  *(video_memory+17) = 'r';
  *(video_memory+19) = 'l';
  *(video_memory+21) = 'd';
  *(video_memory+23) = '!';
  */

  clear_screen();

  set_cursor(get_screen_offset(0, MAX_ROWS-1));
  print("atupal >>");

  char c = 0;
  while (1) {
    if (port_byte_in(0x60) != c) {
      c = port_byte_in(0x60);
      if (c > 0) {
        char s[4];

        s[0] = (c / 16);
        if (s[0] > 9) {
          s[0] = 'a' + s[0] - 10;
        }
        else {
          s[0] = s[0] + '0';
        }

        s[1]  =(c % 16);
        if (s[1] > 9) {
          s[1] = 'a' + s[1] - 10;
        }
        else {
          s[1] = s[1] + '0';
        }

        s[2] = ' ';
        //print("0x");
        //print(s);
        print_char(kbdmap[(c-1)*4], -1, -1, 0);

      }
    }
  }

}
