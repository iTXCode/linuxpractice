#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//线程不安全问题
//多线程环境下程序执行结果
//出现逾期之外的值

//互斥锁/互斥量
pthread_mutex_t mutex;
#define THREAD_NUM  2
int g_count=0;

void *ThreadEntry(void * arg){
  (void) arg;
  for(int i=0;i<50000;++i){
    //如果当前锁已经被其他线程获取到了,
    //当前线程再想获取就会在lock函数处阻塞
    pthread_mutex_lock(&mutex);
    ++g_count;
    pthread_mutex_unlock(&mutex);
    //互斥锁pthread_mutex"挂起等待",一旦线程获取锁失败
    //就会挂起(进入到操作系统提供的的一个等待队列中)
    //这个线程什么时候才能恢复执行,也不是其他线程释放锁
    //立刻就能恢复执行的
    //
    //而是其他线程释放锁之后,当前线程还得看操作系统的心情
    //来决定啥时候恢复执行
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


