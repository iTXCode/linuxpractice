#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){

  printf("hehe\n");
  fwrite("hello world!",strlen("hello world!"),1 ,stdout);
  char buf[1024]="将军的荣耀!";
  write(1,buf,sizeof(buf));
 
  fork(); 
  return 0;
}
