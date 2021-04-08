//
// myln : 簡易 ln コマンド
//
#include <stdio.h>            // perror のため
#include <unistd.h>           // link のため

int main(int argc, char *argv[]) {
  // (1) コマンド行引数の数を確認する
  if (argc!=3) {
    fprintf(stderr, "使用方法： %s file1 file2\n", argv[0]);
    return 1;
  }

  // (2) リンクを作成する
  if (link(argv[1], argv[2])<0) {
    perror("link");           // どっちの引数が原因か不明なので。。。
    return 1;
  }

  return 0;
}
