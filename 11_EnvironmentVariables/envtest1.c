// 全ての環境変数を印刷するプログラム(envtest1.c)
#include <stdio.h>
extern char **environ;

int main(int argc, char*argv[], char*envp[]) {
  for (int i=1; environ[i]!=NULL; i++)
    printf("%s\n", environ[i]);
  return 0;
}

/* 実行例
$ envtest1
TERM=xterm-256color
SHELL=/bin/bash
CLICOLOR=1
...
*/
