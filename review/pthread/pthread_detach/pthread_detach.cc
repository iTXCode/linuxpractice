#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * TheadEntry(void *arg){
  (void) arg;
  int count =5;
  while(count--){
    printf("In TheadEntry:%lu\n",pthread_self());
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,TheadEntry,NULL);
  pthread_detach(tid);
  //分离刚创建的线程
  while(1){
    printf("In main Thead:%lu\n",pthread_self());
    sleep(1);
  }
  return 0;
}

/*pthread_detach:可以是线程组内其他线程对目标线程进程分离,也就是线程自己分
 * */
