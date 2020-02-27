/*
#include<stdio.h>
#include<unistd.h>

int main(){
  while(1){
    sleep(1);
  }
  return 0;
}
*/ 





//#include<stdio.h>
//#include<unistd.h>
//#include<signal.h>
//
//
//
////模拟实现kill
//int main(int argc,char* argv[]){
//  //为了实现简单的kill指令,只进行处理一个进程
//  if(argc!=3){
//    printf("参数有误!./mykill [signo] [pid]\n");
//    return 1;
//  }
//  return 0;
//}


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
