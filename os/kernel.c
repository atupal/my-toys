#include "drivers/screen.h"

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

  print("\n");
  print("atupal >>");

}
