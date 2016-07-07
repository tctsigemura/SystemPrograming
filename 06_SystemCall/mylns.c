/*
 * mylns : 簡易 ln -s コマンド
 */
#include <stdio.h>            /* perror のため */
#include <stdlib.h>           /* exit のため   */
#include <unistd.h>           /* symlink のため */

int main(int argc, char *argv[]) {
  /* 引数の数が多すぎる少なすぎる */
  if (argc!=3) {
    fprintf(stderr, "使用方法： %s file1 file2\n", argv[0]);
    exit(1);
  }

  if (symlink(argv[1], argv[2])<0) {
    perror(argv[2]);                    /* エラー原因は argv[2] だろう */
    exit(1);
  }

  exit(0);
}
