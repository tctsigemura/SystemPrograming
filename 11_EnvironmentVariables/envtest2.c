// LANG環境変数の値を表示するプログラム(envtest2.c)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[], char*envp[]) {
  char *val;
  val = getenv("LANG");
  if (val!=NULL)
    printf("LANG=%s\n", val);
  else
    printf("LANG does not exist.\n");
  return 0;
}

/* 実行例
$ envtest2
LANG=ja_JP.UTF-8
 */
