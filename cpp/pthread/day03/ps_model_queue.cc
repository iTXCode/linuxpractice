#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<vector>
#include<semaphore.h>
#include"blockingqueue.hpp"
//使用队列来实现生产者与消费者模型
//同步互斥不一定非得用互斥锁和条件变量实现
//信号量来完成
//信号量就是一个计数器,表示可用资源的个数
// P 申请资源,计数器  -1
//  V 释放资源 ， 计数器   +1
//当计数器值为 0 的时候，再去 P操作就会发生阻塞

//阻塞队列,一种常见的数据结构,线程安全版本的队列

BlockingQueue<int> queue(100);

void* Product(void *arg){
  (void) arg;
  int count=0;
  while(1){
    queue.Push(++count);
    usleep(789789);
  }
  return NULL;
}

void* Consume(void *arg){
  (void) arg;
  while(1){
    int count =0;
    queue.Pop(&count);
    printf("count =%d\n",count);
    usleep(123123);
  }
  return NULL;
}


//进程间通信  管道  本质上为一个 BlockingQueue  

int main(){
  //第二个参数填成0表示这个信号量只能在当前进程中使用
  //第三个参数表示信号量这个计数器的初始值,申请释放的过程
  //就是对其的P,V 操作
  pthread_t  tid1,tid2;
  pthread_create(&tid1,NULL,Product,NULL);
  pthread_create(&tid2,NULL,Consume,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
 
  return 0;
}

