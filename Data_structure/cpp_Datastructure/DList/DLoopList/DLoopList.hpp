#include<iostream>
#include<assert.h>

template <class T>

struct DListNode{
  DListNode(T value=T())
  :_value(value)
   ,_prev(nullptr)
   ,_next(nullptr)
  {

  }
  T _value;
  DListNode<T>* _prev;
  DListNode<T>* _next;

};

template  <class T>

class DList{
public:
  DList()
  :_head(nullptr)
  {}

  ~DList(){

  }

  void DListDestory(DList<T>* dlist){
    assert(dlist!=NULL);

    delete dlist->_head;
    dlist->_head=nullptr;
  }
  void DListClear(DList<T>* dlist){
    assert(dlist!=NULL);

    DListNode<T>* cur=dlist->_head->_next;
    while(cur!=dlist->_head){
      DListNode<T>* tmp=cur->_next;
      cur->_prev->_next=cur->_next;
      cur->_next->_prev=cur->_prev;
      delete cur;
      cur=tmp;
    }
  }

  DListNode<T>* DListBuyNode(const T& value){
    DListNode<T>* node=new DListNode<T>(value);
    node->_prev=node->_next=nullptr;
  }

  void DListInit(DList<T>* dlist){
    assert(dlist!=NULL);

    DListNode<T>* node=new DListNode<T>(0);
    dlist->_head=node;
    dlist->_head->_next=dlist->_head->_prev=dlist->_head;
  }

  void DListPushFront(DList<T>* dlist,const T&value){
    assert(dlist!=NULL);

    DListNode<T> *node=new DListNode<T> (value);
    node->_next=dlist->_head->_next;
    dlist->_head->_next->_prev=node; 
    dlist->_head->_next=node;
    node->_prev=dlist->_head;
  }

  void DListPushBack(DList<T>* dlist,const T& value){
    assert(dlist!=NULL);

    DListNode<T>* node=new DListNode<T> (value);
    dlist->_head->_prev->_next=node;
    node->_prev=dlist->_head->_prev;
    node->_next=dlist->_head;
    dlist->_head->_prev=node;
  }
  
  void DListPopFront(DList<T> *dlist){
    assert(dlist!=NULL);
    
    DListNode<T>* tmp=dlist->_head->_next;
    dlist->_head->_next=tmp->_next;
    tmp->_next->_prev=dlist->_head;
    delete tmp;
  }

  void DListPopBack(DList<T>* dlist){
    assert(dlist!=NULL);

    DListNode<T>* tmp=dlist->_head->_prev;
    tmp->_prev->_next=dlist->_head;
    dlist->_head->_prev=tmp->_prev;
    tmp->_prev->_next=dlist->_head;
    delete tmp;
  }
  
  
  DListNode<T> * DListFind(DList<T>* dlist,const T&value){
    assert(dlist!=NULL);

    DListNode<T>* cur=dlist->_head->_next;
    while(cur!=dlist->_head){
      if(cur->_value==value)
        return cur;
      cur=cur->_next;
    }
    return NULL;
  }

  void DListInsertFront(DListNode<T>* pos,const T& value){

    DListNode<T>* node=new DListNode<T>(value);
    pos->_prev->_next=node;
    node->_prev=pos->_prev;
    pos->_prev=node;
    node->_next=pos;
  }
  void DListInsertBack(DListNode<T>* pos,const T& value){
    DListNode<T> *node=new DListNode<T>(value);
    node->_next=pos->_next;
    pos->_next->_prev=node;
    pos->_next=node;
    node->_prev=pos;
  }

  void DListErase(DListNode<T>* pos){
    pos->_prev->_next=pos->_next;
    pos->_next->_prev=pos->_prev;
    delete pos;
  }
  
  void DListPrint(const DList<T>* dlist){
    assert(dlist!=NULL);

    DListNode<T> *cur=dlist->_head->_next;
    while(cur!=dlist->_head){
      std::cout<<cur->_value<<"<-->";
      cur=cur->_next;
    }
    std::cout<<std::endl;
  }
private:
  DListNode<T>* _head;
};
