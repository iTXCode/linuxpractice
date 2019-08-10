#include<stdio.h>
#include<unistd.h>

//main函数的三种形式
//1.没参数
//2.int argc,char *argv[]
//3.int argc,char *argv[],char *env
int main(int  argc,char* argv[]){
  //参数1：参数个数
  //参数2：参数
  //env也是一种字符串数组，当前的环境变量都有啥
  printf("argc:%d\n",argc);
  int i=0;
  for(;i<argc;i++){
    printf("%s\n",argv[i]);
  }
  return 0;
}
