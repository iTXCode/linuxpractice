#include<stdio.h>
#include"bolckingqueue.hpp"


class Task{
public:
  virtual void Run(){
    printf("hello world!\n");
  }
private:
};

class ThreadPool{
public:
  ThreadPool(int n)
  :_queue(100)
   ,_work_num(n)
  {
    for(int i=0;i<_work_num;i++){
      pthread_t tid;
      pthread_create(&tid,NULL,EntryThread,NULL);
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

  void AddTask(Task* task){
   _queue.Push(task); 
  }
private:
  BlockingQueue<Task* > _queue; //这个类型的意义？
  int _work_num;
  std::vector<pthread_t> _workers; 
  static void *EntryThread(void * arg) 
    //设置成静态函数的目的是什么?
    //此处的EntryThread函数设置成私有的原因是什么？
  {
    ThreadPool *pool=(ThreadPool*) arg;  //此处的作用是什么？
    while(1){
      Task* task;
      pool->_queue.Pop(&task);
      task->Run();
      delete task;
    }
  } 
};
