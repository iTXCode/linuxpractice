#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *ThreadEntry(void *arg){
  (void) arg;
  while(1){
    printf("In ThreadEntry %lu\n",pthread_self());
    sleep(1);
  }
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);

  while(1){
    printf("In main Thread%lu\n",pthread_self());
    sleep(1);
  }

  return 0;
}

/*int pthread_create(pthread_t *thread,const pthread_attr_t *attr,void*(*start_routine)(void*),void *arg)
 *thread :返回的线程ID 
 *attr:设置线程的属性,attr为NULL表示使用默认属性
 *start_routine:是个函数地址,线程启动后要执行的函数
 *arg:传回给线程启动函数的参数
 *返回值:成功0,失败返回错误代码
 * */
