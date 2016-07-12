/*
 * myln : 簡易 ln コマンド
 */
#include <stdio.h>            /* perror のため */
#include <stdlib.h>           /* exit のため   */
#include <unistd.h>           /* link のため */

int main(int argc, char *argv[]) {
  /* コマンド行引数の数を確認 */
  if (argc!=3) {
    fprintf(stderr, "使用方法： %s file1 file2\n", argv[0]);
    exit(1);
  }

  if (link(argv[1], argv[2])<0) {
    perror("link");           // どっちの引数が原因か不明なので。。。
    exit(1);
  }

  exit(0);
}
