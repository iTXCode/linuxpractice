#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void *ThreadEntry(void *arg){
  (void) arg;

  int count=5;
  while(count--){
    printf("In ThreadEntry:%lu\n",pthread_self());
    sleep(1);

  }
  pthread_exit(NULL);
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  while(1){
    printf("In main Thread=%lu\n",pthread_self());
    sleep(1);
  }

  return 0;
}

/*功能:线程终止
 *原型:void pthread_exit(void *value_ptr);
 *参数:value_ptr:value_ptr不要指向一个局部变量
 *返回值:无返回值,跟进程一样线程结束的时候无法返回到它的调用者
 * */
