#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  //卡在文件  IO 上
  //最后一个参数必须是NULL，如果不慎程序就是未
  //定义行为
  printf("before execl \n");
  int ret= execl("/usr/bin/ls","/usr/bin/ls","/",NULL);
  printf("after execl\n",ret);
  return 0;
}
