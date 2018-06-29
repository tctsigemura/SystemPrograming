#include <stdio.h>
#include <stdlib.h>                   // getenv() のために必要
int main(int argc, char* argv[]) {
  char *val = getenv("LANG");         // LANG環境変数の値を調べる
  if (val!=NULL) {                    // 見つかったら
    printf("LANG=%s\n", val);         //   値を表示
  } else {                            // 見つからない時は
    printf("LANG does not exist.\n"); //   エラーメッセージを表示
  }
  return 0;                           // 正常終了
}
/* 実行例
$ ./a.out
LANG=ja_JP.UTF-8
 */
