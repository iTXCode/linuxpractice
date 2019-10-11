#include<stdio.h>
#include<unistd.h>

int main(){
  pid_t pid=fork();
  if(pid>0){
    printf("I,m father pid:%d,ppid=%d\n",getpid(),getppid());

  }else if(pid==0){
    printf("I'm child pid=%d,ppid=%d\n",getpid(),getppid());
  }else{
    perror("fork\n");
  }
  return 0;
}
