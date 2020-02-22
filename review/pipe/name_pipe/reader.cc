#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  int fd=open("./myfifo",O_RDONLY);

  if(fd<0){
    perror("reader.cc open");
    return 1;
  }

  while(1){
    char buf[1024]={0};
    ssize_t n=read(fd,buf,sizeof(buf)-1);

    if(n<0){
      perror("read");
      return 1;
    }

    if(n==0){
      //var 有写端关闭,读者已经写完了
      printf("read done!\n");
      return 0;
    }
    buf[n]='\0';
    printf("[reader.c]:%s\n",buf);
  }
  close(fd);
  return 0;
}
