#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>


//互斥锁/互斥量
pthread_mutex_t mutex;
#define THREAD_NUM  1
int g_count=0;

void ModifyCount(){
  pthread_mutex_lock(&mutex);
  ++g_count; 
  printf("before sleep!\n"); 
  sleep(3); //模拟了临界区执行时间比较久的情况 
  printf("after sleep!\n");
  pthread_mutex_unlock(&mutex);
}
void *ThreadEntry(void * arg){
  (void) arg;
  for(int i=0;i<50000;++i){
    ModifyCount();
  }
  return NULL;
}

void MyHandler(int sig){
  (void)sig;
  ModifyCount();
}
int main(){
  signal(SIGINT,MyHandler);
  //SIGINT 2号信号,Ctrl + c
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


