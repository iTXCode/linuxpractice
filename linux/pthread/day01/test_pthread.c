//线程控制的相关函数
////1.创建线程
////2.终止线程
////3.等待线程
////4.线程等待
//
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

void * ThreadEntry(void *arg){
  (void) arg;
  while(1){
    printf("In ThreadEntry %lu\n",
        pthread_self());
    sleep(1);
  } 
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  while(1){
    printf("In mian Thread%lu\n",
        pthread_self());
    sleep(1);
  }
  /*
      int pthread_create(pthread_t *thread,
     const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
     参数1:输出型参数
     参数3:函数指针就相当于这个新进程的入口函数,指定了新线程执行那个代码
     入口函数的参数就是pthread_create的第四个参数
     */
  return 0;
}

