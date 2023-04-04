#include <stdio.h>                       // perror のために必要
#include <stdlib.h>                      // putenv のために必要
#include <unistd.h>                      // execvp のために必要
extern char **environ;                   // 環境変数配列を指すポインタ
int main(int argc, char *argv[], char *envp[])  {
  int i;
  for (i=1; argv[i]!=NULL; i++) {        // コマンド行引数について
    if (putenv(argv[i])!=0)              //   代入の形式は putenv で処理できる
      break;                             //     もしもエラーが発生したら終わり
  }
  if (argv[i]!=NULL) {                   // まだ引数が残っていたら
    execvp(argv[i], &argv[i]);           //   残りはコマンド
    perror(argv[i]);                     //   ここが実行されるならエラー
    return 1;                            //   main の retrun は exit と同じ
  }
  for (i=0; environ[i]!=NULL; i++) {     // ここが実行されるならenvの別の機能
    printf("%s\n", environ[i]);          //   全ての環境変数を印刷
  }
  return 0;
}

/* 実行例
% ./myenv X=Y printenv X                                  <------ (1)
Y
% ./myenv LC_TIME=ja_JP.UTF-8 date
2017年 7月 3日 月曜日 14時05分14秒 JST
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT date                 <------ (2)
2017年 7月 3日 月曜日 05時05分25秒 GMT
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT ls -l myenv.c        <------ (3)
-rw-r--r--  1 sigemura  staff  2372  7  3 05:04 myenv.c
% ls -l myenv.c
-rw-r--r--  1 sigemura  staff  2372 Jul  3 14:04 myenv.c
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
