#include <stdio.h>         // printf, fprintf のために必要
#include <unistd.h>        // fork のために必要
int main() {
  int x = 10;
  int pid;
  pid = fork();                             // この瞬間にプロセスがコピーされる
  if (pid<0) {
    fprintf(stderr, "forkでエラー発生\n");  // エラーの場合
    return 1;
  } else if (pid!=0)   {                    // 親プロセスだけが以下を実行する
    x = 20;                                 //   親プロセスの x を書き換える
    printf("親 pid=%d x=%d\n", pid, x);
  } else {                                  // 子プロセスだけが以下を実行する
    printf("子 pid=%d x=%d\n", pid, x);     //   子プロセスの x は初期値のまま
  }
  return 0;
}
/*  実行例
% ./forktest 
親 pid=8079 x=20              // 親プロセスの出力
子 pid=0 x=10                 // 子プロセスの出力（xの値に注目)
*/
