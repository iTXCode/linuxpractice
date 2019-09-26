#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>



template <class T>

struct SLNode{
public:
  SLNode(T value=T())
  :_value(value)
  ,_next(NULL)
  {

  }

  T  _value;
  SLNode* _next;
};

template<class T>

class SList{
public:
  SList()
  :_head(NULL)
  {}
//初始化
  void SListInit(SList* slist){
  assert(slist!=NULL);
  slist->_head=NULL;
  }

//销毁过程
  void SListDestory(SList *slist){
    assert(slist);
    SLNode<T> *cur=slist->_head;
    SLNode<T>* tmp=NULL;
    while(cur->_next!=NULL){
     tmp=cur;
      free(cur);
      cur=tmp->_next;
    }
    slist->_head=NULL;
  }

//增
//头插
  void SListPushFront(SList *slist,const T& value){
    assert(slist!=NULL);
    SLNode<T>* new_node=new SLNode<T> (value); 
    
    SLNode<T>* cur=slist->_head;
    new_node->_next=cur;
    slist->_head=new_node;
    
  }
//尾插
  void SListpushBack(SList *slist,const  T& value){
    assert(slist!=NULL);
    SLNode<T>* new_node=new SLNode<T> (value);
    SLNode<T>* cur=slist->_head;
    while(cur->_next!=NULL){
      cur=cur->_next;
    }
    cur->_next=new_node;
  }

//删
//头删
  void SListPopFront(SList *slist){
    assert(slist!=NULL);

    SLNode<T> *cur=slist->_head;
    slist->_head=cur->_next;
    delete cur;
  }
//尾删
  void SListPopBack(SList *slist){
    assert(slist!=NULL);

    SLNode<T> *cur=slist->_head;
    while(cur->_next->_next!=NULL){
      cur=cur->_next;
    }
    SLNode<T> *tmp=cur->_next;
    cur->_next=NULL;
    delete tmp;
  }

//打印
  void SListPrint(SList *slist){
    assert(slist!=NULL);

    SLNode<T> *cur=slist->_head;
    while(cur!=NULL){
      printf("%d-->",cur->_value);
      cur=cur->_next;
    }
    std::cout<<std::endl;
  }

//查
  SLNode<T> * SListFind(const SList *slist,const T& value){
    if(slist==NULL)
      return NULL;

    SLNode<T> *cur=slist->_head;
    while(cur!=NULL){
      if(cur->_value==value)
        return cur;
      cur=cur->_next;
    }
    return NULL;
  }

//改
  void  SListNodeUpdate(SLNode<T> *node,const T& value){
    node->_value=value;
  }

//指定位置插入元素
//1-->2-->3-->NULL

  void SListInsertAfter(SLNode<T> *pos,const  T& value){
    SLNode<T> *new_node=new SLNode<T>(value);
     
    new_node->_next=pos->_next;
    pos->_next=new_node;
  }

//删除给定pos位置后面的结点
  void SListEraseAfter(SLNode<T> *pos){
    SLNode<T> * node=pos->_next;
    pos->_next=node->_next;
    delete node;
  }

//指定位置pos 前面插入新结点
  void SListInsertBefore( SList *slist, SLNode<T> *pos,const T& value){
    assert(slist);
    SLNode<T> * cur= slist->_head;
    SLNode<T>* new_node=new SLNode<T> (value);
    if(slist->_head==pos){
      SListPushFront(slist,value);
      return;
    }
    while(cur->_next!=pos){
      cur=cur->_next;
    }
    new_node->_next=pos;
    cur->_next=new_node;
  }
private:
  SLNode<T>* _head;
};

