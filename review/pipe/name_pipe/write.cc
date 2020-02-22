#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>



int main(){
  int fd=open("./myfifo",O_WRONLY);

  if(fd<0){
    perror("open error");
    return 1;
  }

  while(1){
    printf("->");
    fflush(stdout);

    char buf[1024]={0};
    //用于存储用户输入的内容
    read(0,buf,sizeof(buf)-1);

    write(fd,buf,strlen(buf));
  }

  close(fd);
  return 0;
}
