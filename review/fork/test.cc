#include<stdio.h>
#include<unistd.h>

int main(){
  int count=0;
  pid_t ret=fork();
  
  if(ret>0){
    count++;
    printf("I'm father count=%d  pid:%d ppid:%d addr=%p\n",count,getpid(),getppid(),&count);  
  }else if(ret==0){
    count++;
  printf("I'm child count=%d  pid:%d ppid:%d addr=%p\n",count,getpid(),getppid(),&count); 
  }else{
    perror("fork");
  }
  return 0;
}
