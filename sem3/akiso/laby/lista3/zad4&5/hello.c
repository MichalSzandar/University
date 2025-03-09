#include "types.h"
#include "stat.h"
#include "user.h"

// A simple program in C that uses ANSI escape sequences to change colors in terminal in xv6 os

int main()
{
  char escape_seq[3];
  char *text = "Hello World\n";

  for(int i = 0; i< 256; i++){
    escape_seq[0] = 0x1B;
    escape_seq[1] = i;
    escape_seq[2] = '\0';
    write(1, escape_seq, 3);
    write(1, text, 14);
    for(volatile int j = 0; j<100000000; j++){
    }
  }
  escape_seq[1] = 7;
  write(1, escape_seq, 3);
  exit();
}
