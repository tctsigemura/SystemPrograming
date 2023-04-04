#include <stdio.h>                              // perror のため
#include <stdlib.h>                             // putenv のため
#include <unistd.h>                             // fork, execve のため
#include <sys/wait.h>                           // wait のため
#include <fcntl.h>                              // open のため
char *execpath="/bin/date";                     // date プログラムのパス
char *args[] = { "date", NULL };                // date プログラムの argv
int main(int argc, char *argv[], char *envp[]) {
  for (int i=1; i<argc; i=i+2) {                // コマンド行引数の各組について
    int pid = fork();                           // 分身(子プロセス)をつくる
    if (pid < 0) {                              // fork に失敗した場合は
      perror(argv[0]);                          //   fork のエラーメッセージ
      return 1;                                 //   エラー終了する
    }
    if (pid != 0) {                             // 親プロセスなら
      int status;                               //   子プロセスの終了を待つ
      wait(&status);
    } else {                                    // 子プロセスなら
      if (putenv(argv[i]) < 0) {                //   環境変数を変更する
	perror(argv[i]);                        //   putenv が失敗した場合
	return 1;                               //   エラー終了する
      }
      if (argv[i+1]!=NULL) {                    //   ファイル名あれば
	close(1);                               //     標準出力をクローズし
	int fd = open(argv[i+1],                //      ファイルをオープンし
              O_WRONLY|O_CREAT|O_TRUNC, 0644);  //       リダイレクト完了
	if (fd < 0) {                           //     open がエラーなら
	  perror(argv[i+1]);                    //      メッセージを出力し
	  return 1;                             //       エラー終了する
	} else if (fd != 1) {
	  fprintf(stderr, "リダイレクト失敗\n");//     原因不明のエラーなら
	  return 1;                             //      エラー終了する
	}
      }
      execv(execpath, args);                    // date プログラムに変身する
      // ここが実行されるならエラーが発生
      perror(execpath);                         // エラーメッセージを出力して
      return 1;                                 // エラー終了する
    }
  }
  return 0;
}
/* 実行例
% ./a.out TZ=Cuba c.txt TZ=Europe/Rome r.txt
% cat c.txt r.txt
Thu Jul 19 21:42:40 CDT 2018
Fri Jul 20 03:42:40 CEST 2018
*/
