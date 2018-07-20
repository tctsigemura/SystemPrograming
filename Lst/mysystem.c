// mysytem.c : system 関数もどきとテストドライバ
#include <stdio.h>
#include <unistd.h>    // fork, execXX
#include <sys/types.h> // wait
#include <sys/wait.h>  // wait
int mysystem(char *command) {                    // 課題の関数 mysystem()
  int pid, stat;
  if (command==NULL) return -1;                  // systemの仕様に似せる
  pid=fork();
  if (pid<0) return -1;
  if (pid==0) {                                  // 子プロセスは
    execl("/bin/sh", "sh", "-c", command, NULL); //   /bin/shへ変身
    return 127;                                  //   失敗したら127を返す
  } else {                                       // 親プロセスは
    while(wait(&stat)!=pid)                      //   /bin/shの終了を待つ
      ;
  }
  return stat;                                   // 親プロセスは/bin/shの
}                                                //   終了ステータスを返す
// テストドライバ
int main(int argc, char *argv[]) {
  int r;
  if (argc!=2) {
    fprintf(stderr, "使い方 : %s コマンド文字列\n", argv[0]);
    return 1;
  }
  r = mysystem(argv[1]);
  printf("r = %08x\n", r);
  return 0;
}

/* 実行例
$ ./mysystem ls
a.txt      mysystem   mysystem.c
r = 00000000
$ ./mysystem "ls -l"
total 40
-rw-r--r--  1 sigemura  staff     4 Jul 20 10:50 a.txt
-rwxr-xr-x  1 sigemura  staff  8700 Jul 20 10:50 mysystem
-rw-r--r--  1 sigemura  staff  1964 Jul 20 10:50 mysystem.c
r = 00000000
$ ./mysystem "cat a.txt"
abc
r = 00000000
$ ./mysystem "cat aa.txt"                <---- エラーが発生する場合
cat: aa.txt: No such file or directory   <---- catが表示したエラーメッセージ
r = 00000100
$ ./mysystem "ccat a.txt"                <---- エラーが発生する場合
sh: ccat: command not found              <---- shが表示したエラーメッセージ
r = 00007f00
*/
