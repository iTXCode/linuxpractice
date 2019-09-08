#include"bolckingqueue.hpp"
#include<vector>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

BlockingQueue<int> queue(100);

void *Product(void *arg){
  (void)arg;
  int count=0;
  while(1){
    queue.Push(++count);
    usleep(789789);
    //等待队列中的元素被取走
  }
  return NULL;
}

void* Consume(void *arg){
  (void )arg;
  while(1){
    int count;
    queue.Pop(&count);
    printf("count=%d\n",count);
    usleep(123123);
  }
  return NULL;
}


int main(){
  pthread_t  tid1,tid2;
  pthread_create(&tid1,NULL,Product,NULL);
  pthread_create(&tid2,NULL,Consume,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  return 0;
}
