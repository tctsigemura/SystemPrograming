#include <stdio.h>                       // perror のために必要
#include <stdlib.h>                      // putenv のために必要
#include <unistd.h>                      // execvp のために必要

extern char **environ;                   // 環境変数配列を指すポインタ

int main(int argc, char *argv[], char *envp[])  {
  for (int i=1; argv[i]!=NULL; i++) {    // コマンド行引数について
    if (putenv(argv[i])!=0) {            //   "X=Y" 形式は putenv で処理できる
      execvp(argv[i], &argv[i]);         //     エラーなら残りはコマンド
      perror(argv[i]);                   //     ここが実行されるならexecエラー
      return 1;                          //     main の retrun は exit と同じ
    }
  }
  for (int i=0; environ[i]!=NULL; i++) { // ここが実行されるならenvの別の機能
    printf("%s\n", environ[i]);          //   全ての環境変数を印刷
  }
  return 0;
}

/* 実行例
% ./myenv printenv LANG
ja_JP.UTF-8
% ./myenv LANG=C printenv LANG                            <------ (1)
C
% date
Tue Jun 27 13:43:36 JST 2023
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT date                 <------ (2)
2023年 6月27日 火曜日 04時43分58秒 GMT
% ls -l myenv.c 
-rw-r--r--  1 sigemura  staff  1955 Jun 27 13:42 myenv.c
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT ls -l myenv.c        <------ (3)
-rw-r--r--  1 sigemura  staff  1955  6 27 04:42 myenv.c
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT                      <------ (4)
TERM_PROGRAM=iTerm.app
TERM=xterm-256color
SHELL=/bin/bash
CLICOLOR=1
...
TZ=GMT
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT ddd                  <------ (5)
ddd: No such file or directory
%
(1) 基本的な動作確認
(2) 複数の環境変数を変更した場合の動作確認
(3) コマンドに引数がある場合の動作確認
(4) コマンドがない場合の動作確認
(5) exec に失敗する場合の動作確認
*/
