/*
 *  mysystem.c : system 関数のクローン
 */

#include <stdio.h>
#include <stdlib.h>    // exit, system のため
#include <unistd.h>    // fork, execXX のため
#include <sys/wait.h>  // wait のため
#include "mysystem.h"

int mysystem(char *command) {                    // 課題の関数 mysystem()
  int status = 0;
  pid_t pid;
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
  }
  return status;                                 // 親プロセスは/bin/shの
}                                                //   終了ステータスを返す

/* 実行例
% make
cc -Wall -std=c99 -o mysysmain mysysmain.c  mysystem.c
% ./mysysmain                           <-- コマンド行引数が不足
使い方 : ./mysysmain コマンド文字列
% ./mysystem ls -l                      <-- コマンド行引数が多すぎる
使い方 : ./mysysmain コマンド文字列
% ./mysysmain "ls -l README.md"         <-- 正常にコマンドが実行できる
mysystem:
-rw-r--r--@ 1 sigemura  staff  1966 Jul  7 16:51 README.md
retval = 00000000
system:
-rw-r--r--@ 1 sigemura  staff  1966 Jul  7 16:51 README.md
retval = 00000000
% ./mysysmain "cat a"                   <-- catがエラーを起こす場合
mysystem:
cat: a: No such file or directory
retval = 00000100
system:
cat: a: No such file or directory
retval = 00000100
% ./mysysmain "ccat a"                  <-- shがエラーを起こす場合
mysystem:                                   shが起動できない場合と同じ
sh: ccat: command not found
retval = 00007f00
system:
sh: ccat: command not found
retval = 00007f00
% sh -c "ccat a"                        <-- 参考までに：
sh: ccat: command not found                 shはこのように呼び出されている
% echo $?                                   この時の終了ステータスは127
127
*/
