#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  int fd=open("./log",O_CREAT | O_RDWR);
  if(fd<0){
    perror("open");
    return 1;
  }
  close(1);
  dup2(fd,1);
  for(; ;){
    char buf[1024]={0};
    ssize_t read_size=read(0,buf,sizeof(buf)-1);
    //sizeof(buf)-1 的目的是避免访问越界
    if(read_size<0){
      perror("read");
      break;
    }
    printf("%s",buf);
    fflush(stdout);
  }
  return 0;
}

