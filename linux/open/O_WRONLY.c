#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
  int fd=open("./myfile.txt",O_WRONLY);
  if(fd<0){
    perror("open");
    return 1;
  }

  char buf[1024]={"将军的荣耀\n"};
  ssize_t n=write(fd,buf,strlen(buf));
  buf[n]='\0';
  printf("%d\n",n);
  printf("%s",buf);
  close(fd);
  return 0;
}
