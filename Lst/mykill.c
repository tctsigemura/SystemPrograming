#include <stdio.h>
#include <stdlib.h>                 // atoi のために必要
#include <signal.h>                 // kill のために必要

int main(int argc, char *argv[]) {
  if (argc!=3) {
    fprintf(stderr, "Usage : %s SIG PID\n", argv[0]);
    return 1;
  }

  int sig = atoi(argv[1]);          // 第１引数
  int pid = atoi(argv[2]);          // 第２引数

  if (kill(pid,sig)<0) {
    perror(argv[0]);
    return 1;
  }
  return 0;
}
