#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
  int fd=open("./myfile.txt",O_RDONLY);
  if(fd<0){
    perror("open");
    return 1;
  }
  char buf[1024]={0};
  ssize_t n=read(fd,buf,sizeof(buf)-1);
  buf[n]='\0';
  printf("%s",buf);
  close(fd);
  return 0;
}
