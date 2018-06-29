//
// mylns : 簡易 ln -s コマンド
//
#include <stdio.h>            // perror のため
#include <unistd.h>           // symlink のため

int main(int argc, char *argv[]) {
  // (1) コマンド行引数の数を確認する
  if (argc!=3) {
    fprintf(stderr, "使用方法： %s file1 file2\n", argv[0]);
    return 1;
  }

  // (2) シンボリックリンクを作る
  if (symlink(argv[1], argv[2])<0) {
    perror(argv[2]);          // エラー原因は argv[2] だろう
    return 1;
  }

  return 0;
}
