#include<stdio.h>
#include<unistd.h>


int main(){
  pid_t pid=fork();
  if(pid>0){
    printf("I'm father pid=%d ppid=%d 返回值=%d\n",getpid(),getppid(),pid);
  }else if(pid==0){
    printf("I'm child pid=%d ppid=%d 返回值=%d\n",getpid(),getppid(),pid);
  }else{
    perror("fork");
  }
  return 0;
}
