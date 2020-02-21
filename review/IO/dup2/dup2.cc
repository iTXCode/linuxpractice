#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
  int fd=open("./log",O_CREAT|O_RDWR);

  if(fd<0){
    //文件打开失败
   perror("open");
   exit(1);
  }

  close(1);
  dup2(fd,1);
  for(;;){
    char buf[1024]={0};
    ssize_t read_size=read(0,buf,sizeof(buf)-1);
    

    if(read_size<0){
      perror("read");
      break;
    }      
    printf("%s\n",buf);
    fflush(stdout);
  }
  return 0;
}
