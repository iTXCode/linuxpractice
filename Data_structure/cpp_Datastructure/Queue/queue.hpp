#pragma once 
#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<assert.h>

template <class T>

struct Node{
    Node(const T val)
    :_value(val)
    ,_next(NULL)
    {
    }
    T _value;
    Node *_next;
};

template<class T>
class Queue{
public:
    Queue(){
        front=NULL;
        rear=NULL;
        size=0;
    }
   void  QueuePush(Queue<T>* queue,const T val){
        if(queue->front==NULL){
            queue->front=queue->rear=new Node<T>(val);
            ++queue->size;
            return;
        }else{
            Node<T>* cur=queue->front;
            if(queue->rear!=NULL){
            queue->rear->_next=new Node<T>(val);
            queue->rear=queue->rear->_next;
            ++queue->size;
            }
            
        }
    }

    void QueuePop(Queue<T>* queue){
        assert(queue!=NULL);
        //尾删
        Node<T>*cur=queue->front;
        if(queue->front==queue->rear){
            delete queue->front;
            queue->size--;
            return;
        }else{
            while(cur->_next!=queue->rear){
            cur=cur->_next;
        }
        delete queue->rear;
        queue->size--;
        queue->rear=cur;
        }
        
        
    }


    void PrintQueue(Queue<T>* queue){
        if(queue->size==0){
            printf("队列已经为空了!\n");
            return ;
        }
        Node<T>* cur=queue->front;
        for(int i=0;i<queue->size;i++){
            std::cout<<cur->_value<<" ";
            cur=cur->_next;
        }
        std::cout<<std::endl;
    }

    //销毁队列
    void DestoryQueue(Queue<T>* queue){
        assert(queue!=NULL);
        for(int i=0;i<queue->size;i++){
            QueuePop(queue);
        }
       queue->front=queue->rear=NULL;
       queue->size=0;
    }


    //返回队列的规模大小
    int Size(){
        return size;
    }
    

    //判断队列是否为空
    bool EmptyQueue(Queue<T>* queue){
        if(queue->size==0){
            return true;
        }else{
            return false;
        }
    }
private:
    Node<T>* front;
    Node<T>* rear;
    int size;
};