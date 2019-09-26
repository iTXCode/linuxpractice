#include<iostream>
#include<assert.h>
#include<stdlib.h>

template <class T>

struct DListNode{
  DListNode(const T& value=T(),DListNode* next=nullptr)
  :_value(value)
   ,_next(next)
  {
  }
  T  _value;
  DListNode* _next;
};

template <class T>
class  DList{
public:
  DList()
    :_head(nullptr)
  {

  }

  //用于申请新的结点
  DListNode<T>* DListBuyNode(const T& value){
    DListNode<T> * node=new DListNode<T> (value);
    return node;
  }


  void DListInit(DList<T>* dlist){
    assert(dlist!=NULL);

    dlist->_head=DListBuyNode(0);
    dlist->_head->_next=NULL;
  }
 

  void DListClear(DList<T>* dlist){
    assert(dlist!=NULL);

    DListNode<T>* cur=dlist->_head->_next;
    while(cur!=NULL){
      DListNode<T> * tmp=cur;
      delete tmp;
      cur=cur->_next;
    }
  }

  void DListDestory(DList<T> *dlist){
    assert(dlist!=NULL);

    free(dlist->_head);
    dlist->_head=NULL;
  }

  void DListPushFront(DList<T>* dlist,const T& value){
    assert(dlist!=NULL);

    DListNode<T>* node=DListBuyNode(value);
    node->_next=dlist->_head->_next;
    dlist->_head->_next=node;
  }

  void DListPushBack(DList<T>* dlist,const T& value){
    assert(dlist!=NULL);

    DListNode<T>* node=DListBuyNode(value);
    DListNode<T>* cur=dlist->_head->_next;
    while(cur->_next!=NULL){
      cur=cur->_next;
    }
    cur->_next=node;
    node->_next=NULL;
  }
  
  void DListPopFront(DList<T>* dlist){
    assert(dlist!=NULL);

    DListNode<T> *cur=dlist->_head->_next;
    dlist->_head->_next=cur->_next; 
    delete cur;
  }
  
  void DListPopBack(DList<T>* dlist){
    assert(dlist!=NULL);

    DListNode<T>* cur=dlist->_head->_next;

    while(cur->_next->_next!=NULL){
      cur=cur->_next;
    }
    DListNode<T>* tmp=cur->_next;
    delete tmp;
    cur->_next=NULL;
  }
 
  DListNode<T>* DListFind(const DList<T>* dlist,const T& value){
    assert(dlist!=NULL);

    DListNode<T>* cur=dlist->_head->_next;
    while(cur!=NULL){
      if(cur->_value==value)
        return cur;
      cur=cur->_next;
    }
    return NULL;
  }

  void DListPosUpdate(DListNode<T>* pos,const T& value){
    pos->_value=value;
  }

  void DListInsertBack(DList<T>* dlist,DListNode<T> *pos,const T& value){
    assert(dlist!=NULL);
    
    DListNode<T>* node=DListBuyNode(value);
    DListNode<T>* cur=dlist->_head->_next;
    while(cur!=pos){
      cur=cur->_next;
    }
    node->_next=cur->_next;
    cur->_next=node;
  }

  void DListInsertFront(DList<T>* dlist,DListNode<T> *pos,const T& value){
    assert(dlist!=NULL);

    DListNode<T>* node=DListBuyNode(value);
    DListNode<T>* cur=dlist->_head->_next;
    while(cur->_next!=pos){
      cur=cur->_next;
    }
    node->_next=cur->_next;
    cur->_next=node;
  }

  //删除pos位置的结点
  void DListEraseAfter(DListNode<T>* pos){
    if(pos->_next==NULL||pos->_next->_next==NULL){
      printf("删除的结点非法！\n");
      return ;
    }
    pos->_next=pos->_next->_next;
    delete pos;
  }

  void DListPrint(DList<T>* dlist){
    assert(dlist!=NULL);

    DListNode<T> *cur=dlist->_head->_next;
    while(cur!=NULL){
      std::cout<<cur->_value<<"-->";
      cur=cur->_next;
    }
    std::cout<<std::endl;
  } 
private:
  DListNode<T> * _head; 
} ;
