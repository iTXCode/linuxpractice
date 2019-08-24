#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdlib.h>
#include<stdint.h>


#define THREAD_NUM 4
#define SIZE  1000000
typedef struct Arg{
  int beg;
  int end;
  int *arr; 
}Arg;


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
void *ThreadEntry(void *arg){
  Arg *p= (Arg*)arg;
  Calc(p->arr,p->beg,p->end);
  return NULL;
}


int main(){
  Arg arg[THREAD_NUM];
  int base=0;
  int *arr=(int *)malloc(sizeof(int)*SIZE);
  for(int i=0;i<SIZE;++i){
    arg[i].beg=base;
    arg[i].end=SIZE/THREAD_NUM;
    arg[i].arr=arr;
    base+=SIZE/THREAD_NUM;
  }
  pthread_t tid[THREAD_NUM];
  int64_t beg=GetUs();
  for(int i=0;i<THREAD_NUM;++i){
   pthread_create(&tid[i],NULL,ThreadEntry,&arg[i]);
  }
  for(int i=0;i<THREAD_NUM;++i){
    pthread_join(tid[i],NULL);
  }

  int64_t end=GetUs();

  printf("执行时间为%ld 微秒\n",end-beg);
  return 0;
}
