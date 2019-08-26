/////////////////////////////////////////////////////////////////////// 
//模拟实现线程池
///////////////////////////////////////////////////////////////////  


/*
线程池:创建的开销也不是完全可以忽略不计的 
线程池对象启动的时候会创建一组线程
每个线程都需要完成一定的任务(执行一定的代码逻辑
，这个逻辑是由调用者来决定的)
*/
#include<stdio.h>
#include"blockingqueue.hpp"
#pragma once 
class Task{
  //用来表示具体的任务
  public:
    virtual void Run(){
      //虚函数:
      printf("hello\n");
    }

    virtual ~Task(){

    }
};

//提前把线程创建好,避免频繁创建销毁线程的开销
//线程不必一次创建太多,复用一个线程来完成多个任务
class ThreadPool{
public:
  //n表示创建线程的数量
  ThreadPool(int n)
  :_queue(100)
   ,_work_num(n)
  {
    //创建出若干个线程
    for(int i=0;i<_work_num;++i){
      pthread_t tid;
      pthread_create(&tid,NULL,ThreadEntry,this);
      _workers.push_back(tid);
    }
  }

   ~ThreadPool(){
    //先让线程退出,然后再回收
    for(size_t  i=0;i<_workers.size();++i){
      pthread_cancel(_workers[i]);
    }
    for(size_t i=0;i<_workers.size();++i){
      pthread_join(_workers[i],NULL);
    }
  }
  //使用线程池的时候,就需要有调用者加入一些任务
  //让线程池去执行
  void  AddTask(Task *task){
    _queue.Push(task);
  }
private:
  BlockingQueue<Task *> _queue;
  int  _work_num; //工作线程的数量
  std::vector<pthread_t> _workers;//记录有哪些工作线程
  static void* ThreadEntry(void *arg){
  ThreadPool* pool=(ThreadPool* ) arg;
  while(true){
    //循环中尝试从阻塞队列中获取任务
    //获取到一个任务就执行一个任务
    Task *task=NULL;
    pool->_queue.Pop(&task);
    //task 表面上看是一个Task* 类型，实际上指向的是MyTask*
    //执行的是  子类,用户自定制的逻辑：
    task->Run();
    delete task;
  }
  }
};
