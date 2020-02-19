#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(){
  int fd=open("myfile.txt",O_RDONLY);

  if( fd<0 ){
    perror("read");
    return 1;
  }

  char buf[1024]={0};

  ssize_t n=read(fd,buf,sizeof(buf)-1);

  buf[n]='\0';
  printf("n=%d\n",n);
  printf("%s\n",buf);
  close(fd);
  return 0;
}


/*
 *1.打开文件描述符
 *2.判断文件描述符创建是否成功
 *3.准备一段缓冲区,用来存储读取到的内容
 *4.读取指定文件中的内容(指明了文件描述符\缓冲区、缓冲区大小)
 *5.将读取到的内容拷贝进准备好的缓冲区
 * */
