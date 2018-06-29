//
// ファイルのモードを変更するプログラム
//
#include <stdio.h>       // perror のため
#include <stdlib.h>      // strtol 等のため
#include <sys/stat.h>    // chmod のため

int main(int argc, char *argv[]) {
  // (1) 使い方が正しいか確認する
  if (argc<3) {
    fprintf(stderr, "使用方法 : %s <8進数> <file> [<file>...]\n", argv[0]);
    return 1;
  }

  // (2) argv[1] を 8進数と見做し int に変換する
  char *ptr;
  int mode = strtol(argv[1], &ptr, 8);  // 8進数を表す文字列の値を整数で求める
  if (*argv[1]=='\0' || *ptr!='\0') {
    fprintf(stderr, "\'%s\' : 8進数の形式が不正\n", argv[1]);
    return 1;
  }
  if ((mode & ~0777)!=0) {
    fprintf(stderr, "\'%s\' : 8進数の値が不正\n", argv[1]);
    return 1;
  }

  // (3) ファイルのモードを変更する
  for (int i = 2; i<argc; i++) {
    if (chmod(argv[i], mode)<0) {
      perror(argv[i]);
      return 1;
    }
  }

  return 0;
}
