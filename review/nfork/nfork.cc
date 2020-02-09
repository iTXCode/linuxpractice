#include<stdio.h>
#include<unistd.h>


int main(){
  int i=0;
  for(;i<5;i++){
    pid_t ret=fork();
    if( ret==0 ){
      break;
    }else if(ret==-1){
      perror("fork");
    }
  }

  if(i<5){
    //子进程需要执行的代码
    sleep(i);
    printf("child[%d]:%d,ppid:%d\n",i,getpid(),getppid());
  }else{
    //此处的代码由父进程执行
    sleep(i);
    printf("father[%d]:%d,ppid:%d\n",i,getpid(),getppid());
  }
  return 0;
}

