#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadEntry(void *arg){
  (void) arg;

  while(1){
    printf("In ThreadEntry:%lu\n",pthread_self());
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);

  while(1){
    printf("In main:%lu\n",pthread_self());
    pthread_cancel(tid);
    sleep(1);
  }
  return 0;
}
/*【功能】
 * 取消一个执行中的线程
 * 【原型】
 * int pthread_cancel(pthread_t thread)
 * 【参数】
 * thread:线程ID
 * 【返回值】
 * 成功返回0,失败返回错误码
 * */


/*1.让线程入口函数执行结束(最主要使用的结束方式)
 *2.pthread_exit 让本线程结束,pthread_exit 参数是一个void* 表示线程结束的返回结果
 *3.pthread_cancel 让任意一个线程结束(本进程中的线程)，不太推荐使用
 *pthread_cancel 执行后对应的线程不一定立刻结束

 * */
