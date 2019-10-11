#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

//多线程利用多核资源
//该程序负责占用两个CPU
void *ThreadEntry(void *arg){
  (void) arg;
  while(1);
  return NULL;
}

int main(){
  pthread_t tid;
   // pthread_t tid,tid1,tid2;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  // pthread_create(&tid1,NULL,ThreadEntry,NULL);
  // pthread_create(&tid2,NULL,ThreadEntry,NULL);
  while(1);
  return 0;
//CPU 的功率是有限度的
//当线程数目达到CPU的上线的时候,继续增加线程数目，会
//降低CPU的效率,线程争夺CPU资源,CPU花费更多的时间在
//线程之间切换
}

/*
CPU密集型/IO密集型(不占CPU) 
 */

















