
//#include<stdio.h>
//#include<unistd.h>
//
//int main(){
//  while(1){
//    sleep(1);
//  }
//  return 0;
//}
// 





#include<stdio.h>
#include<unistd.h>
#include<signal.h>


//模拟实现kill
int main(int argc,char* argv[]){
  //为了实现简单的kill指令,只进行处理一个进程
  if(argc!=3){
    printf("参数有误!./mykill [signo] [pid]\n");
    return 1;
  }
  return 0;
}

