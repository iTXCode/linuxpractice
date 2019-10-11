#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int g_count=0;

pthread_rwlock_t _lock; 
//定义全局锁用以保证读写的安全
void *Reader(void *arg){
  (void ) arg;
  while(true){
    pthread_rwlock_rdlock(&_lock);
    printf("g_count=%d\n",g_count);
    pthread_rwlock_unlock(&_lock);
    sleep(1);
  }
}


void*  Writer(void* arg){
  (void ) arg;
  int count=0;
  while(true){
    pthread_rwlock_wrlock(&_lock);
    g_count=++count;
    pthread_rwlock_unlock(&_lock);
    sleep(1);
  }
}

int main(){
  pthread_rwlock_init(&_lock,NULL);
  pthread_t tid1,tid2,tid3;
  pthread_create(&tid1,NULL,Reader,NULL);
  pthread_create(&tid2,NULL,Reader,NULL);
  pthread_create(&tid3,NULL,Writer,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  pthread_join(tid3,NULL);
  pthread_rwlock_destroy(&_lock);
  return 0;
}
