#include<stdio.h>
#include<unistd.h>

int count=0;
int main(){
  pid_t pid=fork();
  if(pid>0){
    printf("father:%d,%d,%p\n",getpid(),count,&count);
  }else if(pid==0){
    sleep(1);
    count=100;
    printf("child:%d,%d,%p\n",getpid(),count,&count);
  }
  sleep(1);
  return 0;
}
