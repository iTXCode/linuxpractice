

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void MyHandler(int signo){
  printf("signo=%d\n",signo);
}

int main(){
  //signal 替换了信号原有的处理方式
  //(就会通过signal的返回值来返回)
  //signal(2,MyHandler);
  signal(3,MyHandler);
  signal(2,SIG_IGN);
  //忽略该信号方式
  while(1){
    sleep(1);
  }
  return 0;
}
