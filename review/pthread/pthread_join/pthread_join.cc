#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadEntry(void *arg){
  (void) arg;
  while(1){
    printf("In ThreadEntry\n");
    sleep(1);
  }
  return NULL;
}


int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  printf("In main Thread\n");
  pthread_join(tid,NULL);
  printf("new thread 已经被回收了!\n");
  return 0;
}
/*int pthread_join(pthread_t thead,void **value_ptr);
 * 【参数】
 * thread:线程ID
 * value_ptr：它指向一个指针,后者指向线程的返回值
 * 【返回值】
 * 成功返回0,失败返回错误码
 * */
