//模拟实现线程池
#pragma once  
#include<stdio.h>
#include"bolckingqueue.hpp"


class Task{
public:
  virtual void Run(){
    printf("hello!\n");
  }
  virtual ~Task(){}

};

class ThreadPool{
public:
  ThreadPool(int n)
  :_queue(100)
   ,_work_num(n)
  {
    for(int i=0;i<_work_num;i++){
      pthread_t tid;
      pthread_create(&tid,NULL,ThreadEntry,this);
      _workers.push_back(tid);
    } 
  }

  ~ThreadPool(){
    for(size_t i=0;i<_workers.size();i++){
      pthread_cancel(_workers[i]);
    }
    for(size_t  i=0;i<_workers.size();i++){
      pthread_join(_workers[i],NULL);
    }
  }

  void AddTask(Task *task){
   _queue.Push(task);
  }
private:
  BlockingQueue<Task *> _queue;
  int _work_num;
  std::vector<pthread_t> _workers;

  static void* ThreadEntry(void *arg){
    ThreadPool* pool=(ThreadPool* )arg;
    while(true){
      Task *task=NULL;
      pool->_queue.Pop(&task);
      task->Run();
      delete task;
    }
  }
};
