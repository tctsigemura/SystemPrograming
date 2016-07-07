/*
 * ファイルのモードを変更するプログラム
 */
#include <stdio.h>       // perror のため
#include <stdlib.h>      // exit, strtol 等のため
#include <limits.h>      // strtol のため
#include <sys/stat.h>    // chmod のため

// strtol が受け付ける文字列
// "<空白>* [+|-] [0x] <数字>+"
//           0xNNNN は 16進数、0NNNN は 8進数、その他は 10進数

int main(int argc, char *argv[]) {
  char *ptr;
  int  i, mode;

  if (argc<3) {
    fprintf(stderr, "使用方法 : %s <8進数> <file> [<file>...]\n", argv[0]);
    exit(1);
  }

  mode = strtol(argv[1], &ptr, 8);      // 8進数を表す文字列の値を整数で求める
  if (*argv[1]=='\0' || *ptr!='\0') {
    fprintf(stderr, "\'%s\' : 8進数の形式が不正\n", argv[1]);
    exit(1);
  }

  if ((mode & ~0777)!=0) {
    fprintf(stderr, "\'%s\' : 8進数の値が不正\n", argv[1]);
    exit(1);
  }

  for (i = 2; i<argc; i++) {
    if (chmod(argv[i], mode)<0) {
      perror(argv[i]);
      exit(1);
    }
  }

  exit(0);
}
