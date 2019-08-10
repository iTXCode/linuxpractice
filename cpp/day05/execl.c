#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
  pid_t pid=fork(); //进程不同的话，fork函数的返回值不同
  if(pid==-1){
    perror("fork");
    exit(1);
  }else if(pid>0){
    sleep(1);
    printf("parent_pid:%d\n",getpid());
  }else{
    execlp("/bin/ls","ls","-l","-a",NULL);
  //必须以NULL结尾
  }
  return 0;
}
