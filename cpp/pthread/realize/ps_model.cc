#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<vector>
#include<unistd.h>


std::vector<int>  data;

void *Product(void *arg){
  (void)arg;
  int count=0;
  while(1){
    data.push_back(++count);
    usleep(789789);
  }
  return NULL;
}


void *Consume(void* arg){
  (void)  arg;
  while(1){
    if(!data.empty()){
      //从容器中取出插入到最后一个元素
      //并将其记录并释放
      int result=data.back();
      data.pop_back();
      printf("reslut=%d\n",result);
    }
    usleep(123123);
  }
  return NULL;
}
int main(){
  pthread_t tid1,tid2;
  pthread_create(&tid1,NULL,Product,NULL);
  pthread_create(&tid2,NULL,Consume,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  return 0;
}
