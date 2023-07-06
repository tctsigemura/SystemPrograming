/*
 *  mysystem.c : system 関数のクローンとテストドライバ
 */

#include <stdio.h>
#include <stdlib.h>    // exit, system のため
#include <unistd.h>    // fork, execXX のため
#include <sys/wait.h>  // wait のため

int mysystem(char *command) {                    // 課題の関数 mysystem()
  int pid, status;
  if (command==NULL) {                           // /bin/shが実行可能か？
    return 1;                                    //  「可能」を意味する1を返す
  }
  pid=fork();
  if (pid<0) return -1;                          // forkでエラー
  if (pid==0) {                                  // 子プロセスは
    execl("/bin/sh", "sh", "-c", command, NULL); //   /bin/shへ変身
    exit(127);                                   //   失敗したら127で終了
  } else {
    int r;                                       // 親プロセスは
    while((r=wait(&status))!=pid) {              //   /bin/shの終了を待つ
      if (r<0) return -1;                        //     waitのエラー
    }
    if (WIFEXITED(status) &&                     // 子プロセスが
        WEXITSTATUS(status)==127) {              //   exit(127)で終了したなら
      return 127;                                //   /bin/shのexecエラー
    }
  }
  return status;                                 // 親プロセスは/bin/shの
}                                                //   終了ステータスを返す

// テストドライバ
int main(int argc, char *argv[]) {
  if (argc!=2) {
    fprintf(stderr, "使い方 : %s コマンド文字列\n", argv[0]);
    return 1;
  }

  printf("mysystem:\n");
  int r = mysystem(argv[1]);            // mysystemを実行してみる
  printf("retval = %08x\n", r);         // mysystemが返した値

  printf("system:\n");
  int s = system(argv[1]);              // 比較のために本物systemを実行
  printf("retval = %08x\n", s);         // systemが返した値

  return 0;
}

/* 実行例
% make
cc -Wall -std=c99 -o mysystem mysystem.c
% ./mysystem                            <-- コマンド行引数が不足
使い方 : ./mysystem コマンド文字列
% ./mysystem ls -l                      <-- コマンド行引数が多すぎる
使い方 : ./mysystem コマンド文字列
% ./mysystem ls
mysystem:
Makefile	README.md	mysystem	mysystem.c
retval = 00000000
system:
Makefile	README.md	mysystem	mysystem.c
retval = 00000000
% ./mysystem "ls -l"
mysystem:
total 128
-rw-r--r--@ 1 sigemura  staff     79  7 19 17:37 Makefile
-rw-r--r--@ 1 sigemura  staff   1952  7 19 17:37 README.md
-rwxr-xr-x  1 sigemura  staff  50309  7 19 17:45 mysystem
-rw-r--r--@ 1 sigemura  staff   1486  7 19 17:45 mysystem.c
retval = 00000000
system:
total 128
-rw-r--r--@ 1 sigemura  staff     79  7 19 17:37 Makefile
-rw-r--r--@ 1 sigemura  staff   1952  7 19 17:37 README.md
-rwxr-xr-x  1 sigemura  staff  50309  7 19 17:45 mysystem
-rw-r--r--@ 1 sigemura  staff   1486  7 19 17:45 mysystem.c
retval = 00000000
% ./mysystem "cat a"                    <-- catがエラーを起こす場合
mysystem:
cat: a: No such file or directory
retval = 00000100
system:
cat: a: No such file or directory
retval = 00000100
% ./mysystem "ccat a"                   <-- shがエラーを起こす場合
mysystem:
sh: ccat: command not found
retval = 00007f00
system:
sh: ccat: command not found
retval = 00007f00
% sh -c "ccat a"                        <-- 参考までに：
sh: ccat: command not found                   shはこのように呼び出されている
*/
