#pragma once 

#include<stdio.h>
#include<vector>
#include<pthread.h>
#include<semaphore.h>

template<class T>

class BlockingQueue{
public:
  BlockingQueue(int max_size_)
  :_queue(max_size_)
   ,_head(0)
   ,_tail(0)
   ,_size(0)
   ,_max_size(max_size_)
  {
    sem_init(&_lock,0,1);
    sem_init(&_elem,0,0);
    sem_init(&_blank,0,_max_size);
  }
  ~BlockingQueue(){
    sem_destroy(&_lock);
    sem_destroy(&_elem);
    sem_destroy(&_blank);
  }

  void Push(const T& data){
    sem_wait(&_blank);
    sem_wait(&_lock);
    _queue[_tail]=data;
    ++_size;
    ++_tail;
    sem_post(&_lock);
    sem_post(&_elem);
  }

  void Pop(T *data){
    sem_wait(&_elem);
    sem_wait(&_lock);
    *data=_queue[_head];
    ++_head;
    --_size;
    sem_post(&_lock);
    sem_post(&_blank);

  }
private:
  std::vector<T> _queue;
  int _head;
  int _tail;
  int _size;
  int _max_size;
  sem_t _lock;
  sem_t _elem;
  sem_t _blank;
};

//消息队列中元素从从一端进入
//从另外一端弹出
