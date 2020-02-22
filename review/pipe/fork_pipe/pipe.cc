#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main(){
  int fd[2];
  int ret=pipe(fd);

  if(ret<0){
    perror("pipe");
    return 1;
  }

  ret=fork();

  if(ret>0){
    char buf[1024]="hehe";
    write(fd[1],buf,strlen(buf));
    char buf_output[1024]={0};
    read(fd[0],buf_output,strlen(buf_output)-1);
    printf("father read:%s\n",buf_output);

  }else if(ret==0){

    char buf_output[1024]={0};
    read(fd[0],buf_output,sizeof(buf_output)-1);
    printf("child read:%s\n",buf_output);
  }else{
    perror("fork");
  }

  
  while(1){
    sleep(1);
  }

  close(fd[0]);
  close(fd[1]);
  return 0;
}
