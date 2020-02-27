#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>


//模拟实现kill
int main(int argc,char* argv[]){
  //为了实现简单的kill指令,只进行处理一个进程
  if(argc!=3){
    printf("参数有误!./mykill [signo] [pid]\n");
    return 1;
  }

  //argv[1]==> -9
  int signo=atoi(argv[1]+1);
  //本来的argv[1]指的是命令行第二个参数的首地址
  //此处+1操作使得指针指向首地址的下一个位置
  pid_t pid=atoi(argv[2]);

  int ret=kill(pid,signo);

  if(ret<0){
    perror("kill");
    return 1;
  }
  return 0;
}




/*获取三个参数的指令,例如: kill -9 pid
 * 如何才能获取到后两个命令行参数呢?
 *
 * */
/*如何将字符串转换成数字
 * 
 * */
