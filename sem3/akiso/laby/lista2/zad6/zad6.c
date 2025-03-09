#include<stdio.h>
#include<unistd.h>

//a simple program in C that uses ANSI escape sequences to change colors in terminal

int main(){ 
  for(int i = 0; i<256; i++){
    printf("\033[38;5;%dmHello, world!\033[0m\n", i);
    usleep(10000);
  }
  return 0;
}
