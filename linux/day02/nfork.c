#include<stdio.h>
#include<unistd.h>

int main(){
  int i=0;
  for(;i<5;i++){
  pid_t ret=fork();
  if(ret==0){
    break;
  }else if(ret==-1){
    perror("fork");
  }
  }

  if(i<5){
    sleep(i);
    printf("child[%d]:%d\n",i,getpid());
  }else{
    sleep(i);
    printf("father[%d]:%d\n",i,getpid());
  }
  return 0;
}
