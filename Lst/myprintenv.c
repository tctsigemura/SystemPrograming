/*
 *  myprintenv.c : printenv コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>

extern char **environ;                            // どこかで定義してあるenviron

int main(int argc, char *argv[]) {
  if (argc==1) {                                  // 引数がなかった場合
    for (int i=0; environ[i]!=NULL; i++) {        // 全ての環境変数を表示
      printf("%s\n", environ[i]);
    }
  } else {                                        // 引数があった場合
    char *env = getenv(argv[1]);                  // 環境変数を探す
    if (env==NULL) return 1;                      // 見つからない(エラー終了)
    printf("%s\n", env);                          // 値を表示
  }
  return 0;                                       // 正常終了
}

/* 実行例
% make
cc -Wall -std=c99 -o myprintenv myprintenv.c   <--- エラーも警告もなし
% ./myprintenv USER                            <--- 正常動作のテスト
sigemura
% ./myprintenv HOME                            <--- 正常動作のテスト
/Users/sigemura
% echo $?                                      <--- 終了ステータスを確認
0                                              <---  正常終了
% ./myprintenv NEVER                           <--- 存在しない変数の場合
% echo $?                                      <--- 終了ステータスを確認
1                                              <---  エラー終了
% ./myprintenv USER HOME                       <--- 複数指定しても最初だけ
sigemura
% ./myprintenv NEVER HOME                      <--- 複数指定して最初が存在しない
% ./myprintenv                                 <--- 引数なしの場合
TERM_PROGRAM=iTerm.app
TERM=xterm-256color
SHELL=/bin/bash
CLICOLOR=1
USER=sigemura
LANG=ja_JP.UTF-8
... 省略 ...
% echo $?                                      <--- 終了ステータスを確認
0                                              <---  正常終了
*/
