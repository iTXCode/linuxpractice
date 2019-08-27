/*
假设将一个很大的数组，把数组中的每个元素都进行
一个乘方运算,再赋值回数组
*/

//
//#include<stdio.h>
//#include<unistd.h>
//#include<pthread.h>
//#include<sys/time.h>
//#include<stdlib.h>
//#include<stdint.h>
//#define SIZE  1000000
//
////时间戳查看 :data +%s
////us ->微秒
////ms ->毫秒
//
//int64_t  GetUs(){
//  //时间戳可能为负(闰秒),返回值类型需为有符号型
//  struct timeval tv;
//  gettimeofday(&tv,NULL);
//  return tv.tv_sec*1000000+tv.tv_usec;
//  //当前的秒数*1000000转化为微秒+当前微秒数
//}
//void Calc(int *arr,int beg,int end){
//  for(int i=beg;i<end;++i){
//    arr[i]=arr[i]*arr[i];
//  }
//}
//int main()
//{
//  //记录开始时间
//  int64_t beg=GetUs();
//  int *arr=(int *)malloc(sizeof(int)*SIZE);
//  Calc(arr,0,SIZE);
//  //记录结束时间
//  //两者的差为执行的时间
//  int64_t end=GetUs();
//  printf("执行时间=%ld \n",end-beg);
//  return 0;
//}
//
//
//
////多线程版本



#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdlib.h>
#include<stdint.h>
#define SIZE  1000000

#define  THREAD_NUM  3

typedef struct Arg{
  int beg;
  int end;
  int *arr;
}Arg;

int64_t  GetUs(){
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec*1000000+tv.tv_usec;
 
}
void Calc(int *arr,int beg,int end){
  for(int i=beg;i<end;++i){
    arr[i]=arr[i]*arr[i];
  }
}

void * ThreadEntry(void* arg){
 Arg* p= (Arg*)arg;
 Calc(p->arr,p->beg,p->end);
  return NULL;
}

//线程1 Calc(arr,0,SIZE/2)
//线程2 Calc(arr,SIZE/32, SIZE)
int main()
{
 int *arr=(int *)malloc(sizeof(int)*SIZE);
 Arg args[THREAD_NUM];
 int base=0;
 for(int i=0;i<THREAD_NUM;++i){
   args[i].beg=base;
   args[i].end=base+ SIZE/THREAD_NUM;
   args[i].arr=arr;
   base+=SIZE/THREAD_NUM;
 }

  int64_t beg=GetUs();
  pthread_t tid[THREAD_NUM];
  for(int i=0;i<THREAD_NUM;++i){
    pthread_create(&tid[i],NULL,ThreadEntry,&args[i]);
  }
  for(int i=0;i<THREAD_NUM;++i){
    pthread_join(tid[i],NULL);
  }
  int64_t end=GetUs();
  printf("执行时间=%ld\n",end-beg);
  return 0;

}
