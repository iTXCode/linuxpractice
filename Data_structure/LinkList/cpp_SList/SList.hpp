#include<iostream>
#include<stdlib.h>
#include<assert.h>


typedef int SLDataType;

typedef struct SLNode{
  SLDataType _value;
  SLNode* _next;
}SLNode;

class  SList{
public:

  SList()
  :_head(NULL)
  {
   
  }
  void SLNodeInit(SList* slist){
    assert(slist!=NULL);
    slist->_head=NULL;
  }

  void SListDestory(SList* slist){
    assert(slist!=NULL);
    SLNode* cur=slist->_head;
    SLNode* tmp=NULL;
    while(cur!=NULL){
        tmp=cur;
        free(cur);
        cur=tmp->_next;
    }
    slist->_head=NULL;
  }

  void SListFrontPush(SList* slist,SLDataType value){
    assert(slist!=NULL);
    
   SLNode *new_node=(SLNode*)malloc(sizeof(SLNode));
   SLNode* cur=slist->_head;
   new_node->_value=value;
   new_node->_next=cur;
   slist->_head=new_node;
  }
   //尾插
  void SListBackPush(SList* slist,SLDataType value){
    assert(slist!=NULL);
    SLNode* new_node=(SLNode*)malloc(sizeof(SLNode));
    SLNode* cur=slist->_head;
    while(cur->_next!=NULL){
      cur=cur->_next;
    }
    new_node->_value=value;
    cur->_next=new_node;
    new_node->_next=NULL;
  }


  void SListPopFront(SList *slist){
    assert(slist!=NULL);
    SLNode* cur=slist->_head;
    slist->_head=slist->_head->_next;
    free(cur);
  }

  //尾删
  void SListPopBack(SList *slist){
    assert(slist!=NULL);
    SLNode* cur=slist->_head;
    while(cur->_next->_next!=NULL){
      cur=cur->_next;
    }
    SLNode* tmp=cur->_next;
    cur->_next=NULL;
    free(tmp);
  }

  SLNode*  SListFind(const SList* slist,SLDataType value){
    if(slist==NULL){
      return NULL;
    }

    SLNode* cur=slist->_head;
    while(cur!=NULL){
      if(cur->_value==value)
      return cur;
      cur=cur->_next;
    }
    
    return NULL;
    //在所给链表中没有找到所需结点
    //返回NULL
  }
  void SListPrint(const SList* slist){
    assert(slist!=NULL);

    SLNode* node=slist->_head;
    while(node->_next!=NULL){
      printf("%d-->",node->_value);
      node=node->_next;
    }
    std::cout<<std::endl;
  }

  //改
  void  SlistNodeUpdate(SLNode *node, SLDataType value){
    node->_value=value;
  }
  
  //指定位置插入元素
  //1-->2-->3-->NULL
  
  void SListInsertAfter(SLNode *pos, SLDataType value){
    SLNode* new_node=(SLNode*)malloc(sizeof(SLNode));
    new_node->_value=value;
    new_node->_next=pos->_next;
    pos->_next=new_node;
  }
  //删除给定pos位置后面的结点
  void SListEraseAfter(SLNode *pos){
    SLNode* cur=pos->_next;
    
    pos->_next=pos->_next->_next;
    free(cur);
  }
  
  //指定位置pos 前面插入新结点
  void SListInsertBefore(SList *slist, SLNode *pos, SLDataType value){
    assert(slist!=NULL);

    SLNode* new_node=(SLNode*)malloc(sizeof(SLNode));
    new_node->_value=value;
    SLNode*  cur=slist->_head;
    while(cur->_next!=pos){
      cur=cur->_next;
    }
    new_node->_next=pos;
    cur->_next=new_node;
  }

private:
  SLNode * _head;
};

