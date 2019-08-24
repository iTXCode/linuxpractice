#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdlib.h>
#include<stdint.h>

#define SIZE  1000000

void  Calc(int *arr,int beg,int end){
  for(int i=beg;i<end;++i)
  {
    arr[i]=arr[i]*arr[i];
  }
}

int64_t  GetUs(){
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec*1000000+tv.tv_usec;
}

int main(){
  int64_t beg=GetUs();
  int *arr=(int *)malloc(sizeof(int)*SIZE);

  Calc(arr,0,SIZE);
  int64_t end=GetUs();
  printf("执行时间为%ld 微秒\n",end-beg);
  return 0;
}
