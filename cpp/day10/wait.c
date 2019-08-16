#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
  pid_t ret=fork();
  if(ret>0){
    printf("father %d\n",getpid());
    int status=0;
    pid_t result=wait(&status);
    printf("result %d status %d \n",result,status);
    if(status&0xff){
      printf("异常终止,信号为%d\n",status& 0x7f);
    }else{
      printf("正常终止,退出码为 %d\n",(status>>8)&0xff);
    }
  }else if(ret==0){
    int count =3;
    while(count>0){
   printf("child %d\n",getpid());
      sleep(1);
      --count;
   
    } 
    exit(1);
  }else{
    perror("fork");
  }
  return 0;
}
