#include <stdio.h>                                // perror のため
#include <stdlib.h>                               // exit のため
#include <unistd.h>                               // fork, execve のため
#include <sys/wait.h>                             // wait のため
#include <fcntl.h>                                // open のため

char *execpath="/bin/date";                       // date プログラムのパス
char *args[] = { "date", NULL };                  // date プログラムの argv
extern char **environ;                            // 自分の環境変数

int main(int argc, char *argv[], char *envp[]) {
  // 各コマンド行引数の組について
  for (int i=1; i<argc; i=i+2) {
    // 分身をつくる
    int pid = fork();
    if (pid < 0) {
      perror(argv[0]);
      return 1;
    }
    
    // 親子プロセスで動きを変える
    if (pid != 0) {                               // 親プロセスなら
      int status;
      wait(&status);
    } else {                                      // 子プロセスなら
      // 環境変数を変更する
      if (putenv(argv[i]) < 0) {
	perror(argv[i]);                          // putenv が失敗した場合
	return 1;
      }

      // ファイル名がある場合のみリダイレクトする
      if (argv[i+1]!=NULL) {
	close(1);
	int fd = open(argv[i+1],
		      O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd < 0) {
	  perror(argv[i+1]);                      // open のエラーメッセージ
	  return 1;
	} else if (fd != 1) {
	  fprintf(stderr, "リダイレクト失敗\n");  // エラー原因不明の場合
	  return 1;
	}
      }

      // date プログラムを実行する
      execve(execpath, args, environ);
      perror(execpath);
      return 1;
    }
  }
  return 0;
}

/* 実行例
$ kadai TZ=Singapore a.txt TZ=Cuba c.txt
$ cat a.txt c.txt
Tue Jul 19 22:19:55 SGT 2016
Tue Jul 19 10:19:55 CDT 2016
*/
