/*
 * printenv コマンドもどき(myprintenv.c)
 */

#include <stdio.h>
#include <stdlib.h>

extern char **environ;                            // どこかで定義してあるenviron

int main(int argc, char *argv[], char *envp[]) {
  if (argc==1) {                                  // 引数がなかった場合
    for (int i=0; environ[i]!=NULL; i++)          // 全ての環境変数を表示
      printf("%s\n", environ[i]);
  } else {                                        // 引数があった場合
    char *env = getenv(argv[1]);                  // 環境変数を探す
    if (env==NULL) return 1;                      // 見つからない(エラー終了)
    printf("%s\n", env);                          // 値を表示
  }
  return 0;                                       // 正常終了
}

/* 実行例
$ ./myprintenv USER
sigemura
$ ./myprintenv HOME
/Users/sigemura
$ ./myprintenv USER HOME
sigemura
$ ./myprintenv NEVER
$ ./myprintenv
TERM_PROGRAM=iTerm.app
TERM=xterm-256color
SHELL=/bin/bash
CLICOLOR=1
USER=sigemura
LANG=ja_JP.UTF-8
HOME=/Users/sigemura
LOGNAME=sigemura
LC_TIME=C
... 省略 ...
$
*/
