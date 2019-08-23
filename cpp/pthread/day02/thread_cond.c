#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>



//互斥锁/互斥量
pthread_mutex_t mutex;
pthread_cond_t  cond;
int g_count=0;

void *ThreadEntry1(void * arg){
  (void) arg;
  while(1){
    printf("传球\n");
    pthread_cond_signal(&cond);
    //等待扣篮老哥的信号
    usleep(789789);
  }
  return NULL;
}

void *ThreadEntry2(void *arg){
  (void) arg;
  while(1){
    pthread_cond_wait(&cond,&mutex);
    //TODO 搭配互斥锁
    //执行这个pthread_cond_wait 函数就会导致线程被阻塞
    //阻塞到其他线程发送一个通知
    printf("扣篮\n");
    usleep(123456);
  }
  return NULL;
}
int main(){
  pthread_mutex_init(&mutex,NULL);
  pthread_cond_init(&cond,NULL);
  pthread_t tid1,tid2;

  pthread_create(&tid1,NULL,ThreadEntry1,NULL);
  pthread_create(&tid2,NULL,ThreadEntry2,NULL);

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  return 0;
}


