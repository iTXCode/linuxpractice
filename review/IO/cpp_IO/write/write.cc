#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
//1.打开文件描述符

int main(){
  int fd=open("myfile.txt",O_WRONLY);

  if(fd<0){
    perror("open");
    return 1;
  }

  char buf[1024]="新型肺炎冠状病毒早点过去!";
  
  ssize_t n=write(fd,buf,strlen(buf));
  buf[n]='\0';
  
  printf("n=%d\n",n);
  printf("%s\n",buf);
  close(fd);
  return 0;
}
