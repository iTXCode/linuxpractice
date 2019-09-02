#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


//互斥锁/互斥量
pthread_mutex_t mutex;
#define THREAD_NUM  2
int g_count=0;

void *ThreadEntry(void * arg){
  (void) arg;
  for(int i=0;i<50000;++i){
    pthread_mutex_lock(&mutex);
    ++g_count;
    pthread_mutex_unlock(&mutex);
    }
  return NULL;
}
int main(){
  pthread_mutex_init(&mutex,NULL);
  pthread_t tid[THREAD_NUM];
  for(int i=0; i < THREAD_NUM ; ++i){
    pthread_create(&tid[i],NULL,ThreadEntry,NULL);
  }
  for(int i=0;i<THREAD_NUM;++i){
    pthread_join(tid[i],NULL);
  }
  printf("g_count = %d \n",g_count);
  pthread_mutex_destroy(&mutex);
  return 0;
}


