//一写多读的情况
//添加读写锁

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


//C++ 中自带的 std::thread
//C++11开始，把线程直接纳入到了标准库中
//std::thread  类
//读写锁
pthread_rwlock_t lock;

//一个交易场所
int g_count=0;

//2种角色
void *Reader(void *arg){
  (void)arg;
  while(1){
    pthread_rwlock_rdlock(&lock); //获取读锁
    printf("g_count =%d \n",g_count);
    pthread_rwlock_unlock(&lock);  //释放读锁
    sleep(1);
  }
  return NULL;
}
//当写锁和读锁同时竞争的时候,理论上写锁优先

void *Writer(void *arg){
  (void)arg;
  int count =0;
  while(1){
    pthread_rwlock_wrlock(&lock);//获取写锁
    ++count;
    g_count=count;
    pthread_rwlock_unlock(&lock);//释放写锁 
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_rwlock_init(&lock,NULL);  //初始化读写锁
  pthread_t  tid1,tid2,tid3,tid4;
  pthread_create(&tid1,NULL,Reader,NULL);
  pthread_create(&tid3,NULL,Reader,NULL);
  pthread_create(&tid4,NULL,Reader,NULL);
  pthread_create(&tid2,NULL,Writer,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  pthread_rwlock_destroy(&lock); //销毁锁
  return 0;
}
