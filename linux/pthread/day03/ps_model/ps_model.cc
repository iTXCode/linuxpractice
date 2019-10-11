//#include<iostream>
//#include<stdio.h>
//#include<pthread.h>
//#include<unistd.h>
//#include<vector>
////实现一个生产者消费者模型
////首先得有一个交易场所
//
//std::vector<int>  data;
//
////两个角色(生产者和消费者),两个线程
//
//void *Product(void *arg){
//  (void )arg;
//  //负责将数据放到交易场所中去
//  int count=0;
//  while(1){
//    data.push_back(count++);
//    usleep(789789);
//  }
//  return NULL;
//}
//
//void* Consume(void *arg){
//  (void)  arg;
//  //负责把交易场所中的数据获取出来
//  while(1){
//    //每次取出最后一个元素
//    //int result=data[data.size()-1];
//    //取数据前要先判断容器是否为空防止访问越界
//    if(!data.empty()){
//    int result=data.back();
//    data.pop_back();
//    printf("result = %d \n",result); 
//    }
//    usleep(123123);
//  }
//  return NULL;
//}
//
//
//int main(){
//  pthread_t  tid1,tid2;
//  pthread_create(&tid1,NULL,Product,NULL);
//  pthread_create(&tid2,NULL,Consume,NULL);
//  pthread_join(tid1,NULL);
//  pthread_join(tid2,NULL);
//  return 0;
//}



#if 0
//多个生产者和消费者模型
#include<iostream>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<vector>
//实现一个生产者消费者模型
//首先得有一个交易场所

std::vector<int>  data;

//两个角色(生产者和消费者),两个线程

void *Product(void *arg){
  (void )arg;
  //负责将数据放到交易场所中去
  int count=0;
  while(1){
    data.push_back(count++);
    usleep(789789);
  }
  return NULL;
}

void* Consume(void *arg){
  (void)  arg;
  //负责把交易场所中的数据获取出来
  while(1){
    //每次取出最后一个元素
    //int result=data[data.size()-1];
    //去数据前要先判断容器是否为空防止内存访问越界
    if(!data.empty()){
    int result=data.back();
    data.pop_back();
    printf("result = %d \n",result); 
    }
    usleep(123123);
  }
  return NULL;
}

//段错误原因:C++STL中所提供的容器和算法都是线程不安全的
//C++有两个最核心的要点
//1.和C语言兼容
//2.对性能追求到极致


int main(){
  pthread_t  tid1,tid2,tid3,tid4;
  pthread_create(&tid1,NULL,Product,NULL);
  pthread_create(&tid3,NULL,Product,NULL);
  pthread_create(&tid2,NULL,Consume,NULL);
  pthread_create(&tid4,NULL,Consume,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  return 0;
}
#endif

#if 0
/* 解决C++中线程安全的问题*/

//多个生产者和消费者模型
#include<iostream>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<vector>
//实现一个生产者消费者模型
//首先得有一个交易场所

std::vector<int>  data;
pthread_mutex_t  lock;

//两个角色(生产者和消费者),两个线程

void *Product(void *arg){
  (void )arg;
  //负责将数据放到交易场所中去
  int count=0;
  while(1){
    //加上线层锁
    pthread_mutex_lock(&lock);
    data.push_back(++count);
    pthread_mutex_unlock(&lock);
    usleep(789789);
  }
  return NULL;
}

void* Consume(void *arg){
  (void)  arg;
  //负责把交易场所中的数据获取出来
  while(1){
    //每次取出最后一个元素
    //int result=data[data.size()-1];
    //去数据前要先判断容器是否为空防止内存访问越界
    pthread_mutex_lock(&lock);
    if(!data.empty()){
    int result=data.back();
    data.pop_back();
    printf("result = %d \n",result); 
    }
    pthread_mutex_unlock(&lock);
    usleep(123123);
  }
  return NULL;
}

//段错误原因:C++STL中所提供的容器和算法都是线程不安全的
//C++有两个最核心的要点
//1.和C语言兼容
//2.对性能追求到极致


int main(){
  //初始化线程锁
  pthread_mutex_init(&lock,NULL);
  pthread_t  tid1,tid2,tid3,tid4;
  pthread_create(&tid1,NULL,Product,NULL);
  pthread_create(&tid3,NULL,Product,NULL);
  pthread_create(&tid2,NULL,Consume,NULL);
  pthread_create(&tid4,NULL,Consume,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  pthread_mutex_destroy(&lock);
  return 0;
}

#endif   

/* 解决C++中线程安全的问题
 进一步改进.如果vector中没有数据消费者啥都不做
 ,直到有数据了,才去真正进行消费

在该程序中消费者获取数据的速度比较快
需要消费者来wait
*/

//多个生产者和消费者模型
#include<iostream>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<vector>
//实现一个生产者消费者模型
//首先得有一个交易场所

std::vector<int>  data;
pthread_mutex_t  lock;
pthread_cond_t   cond;
//两个角色(生产者和消费者),两个线程

void *Product(void *arg){
  (void )arg;
  //负责将数据放到交易场所中去
  int count=0;
  while(1){
    //加上线层锁
    pthread_mutex_lock(&lock);
    data.push_back(++count);
    pthread_mutex_unlock(&lock);
    pthread_cond_signal(&cond);
    //每次插入数据就通知消费者来取
    usleep(789789);
  }
  return NULL;
}

void* Consume(void *arg){
  (void)  arg;
  //负责把交易场所中的数据获取出来
  while(1){
    //每次取出最后一个元素
    //int result=data[data.size()-1];
    //去数据前要先判断容器是否为空防止内存访问越界
    pthread_mutex_lock(&lock);
 //这儿最好写成while，而不是if
 //pthread_cond_wait 返回值不一定就是 其他线程  signal 
 //这个函数也可能被信号打断
    while(data.empty()){
      //1.先释放锁
      //2.等待条件就绪(有其他线程调用 pthread_cond_signal)
      //3.如果条件就绪了,重新获取锁
      //1和2必须是原子的
      //加上wait之后最大的意义在于如果没有数据,消费者线程
      //就不需要空转,节省了资源
       pthread_cond_wait(&cond,&lock);
    }
  int result=data.back();
  data.pop_back();
  printf("result = %d \n",result);
  pthread_mutex_unlock(&lock);
  usleep(123123);
  }
  return NULL;
}

//段错误原因:C++STL中所提供的容器和算法都是线程不安全的
//C++有两个最核心的要点
//1.和C语言兼容
//2.对性能追求到极致


int main(){
  //初始化线程锁
  pthread_mutex_init(&lock,NULL);
  pthread_cond_init(&cond,NULL);
  pthread_t  tid1,tid2,tid3,tid4;
  pthread_create(&tid1,NULL,Product,NULL);
  pthread_create(&tid3,NULL,Product,NULL);
  pthread_create(&tid2,NULL,Consume,NULL);
  pthread_create(&tid4,NULL,Consume,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  pthread_join(tid3,NULL);
  pthread_join(tid4,NULL);
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&lock);
  return 0;
}

