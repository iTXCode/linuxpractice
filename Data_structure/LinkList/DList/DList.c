#include"DList.h"



//申请空间的函数
DListNode * DListBuyNode(DLDataType value){
  DListNode* new_node=(DListNode*)malloc(sizeof(DListNode));
  new_node->_value=value;
  new_node->_prev=NULL;
  new_node->_next=NULL;
  return new_node;
}

//初始化
void DListInit(DList *dlist){
  assert(dlist!=NULL);
  dlist->head=DListBuyNode(0);
  dlist->head->_prev=NULL;
  dlist->head->_next=NULL; 
}

//销毁
//1.清空链表
void DListClear(DList *dlist){
  assert(dlist!=NULL);
  assert(dlist->head!=NULL);

  DListNode* cur=dlist->head->_next;
  while(cur->_next!=NULL){ 
    DListNode* tmp=cur;
    cur=cur->_next;
    free(tmp);
  }
  dlist->head->_next=dlist->head->_prev=NULL; 
}


//2.彻底的清空链表，彻底销毁
void DListDestory(DList *dlist){
  assert(dlist!=NULL);
  
  DListClear(dlist);
  free(dlist->head);
  dlist->head=NULL;
}



//增
//头插
void  DListPushFront(DList *dlist,DLDataType value){
  assert(dlist!=NULL);

  DListNode* cur=dlist->head;
  DListNode* new_node=DListBuyNode(value);
  cur->_next->_prev=new_node;
  new_node->_next=cur->_next;
  dlist->head->_next=new_node;
  new_node->_prev=cur;
}
//尾插
void DListPushBack(DList *dlist, DLDataType value){
  assert(dlist!=NULL);

  DListNode* node=DListBuyNode(value);
  DListNode* cur=dlist->head;
  while(cur->_next!=NULL){
    cur=cur->_next;
  }
  cur->_next=node;
  node->_prev=cur;
  node->_next=NULL;
}


//删
//头删
void DListPopFront(DList *dlist){
  assert(dlist!=NULL);

  DListNode* cur=dlist->head;
  dlist->head=cur->_next;
  free(cur);
  dlist->head->_prev=NULL;
}
//尾删
void DListPopBack(DList *dlist){
  assert(dlist!=NULL);
  DListNode* cur=dlist->head;
  while(cur->_next!=NULL){
    cur=cur->_next;
  }
  cur->_prev->_next=NULL;
  free(cur);
}


//查找

DListNode * DListFind(DList *dlist,DLDataType value){
  assert(dlist!=NULL);

  DListNode* cur=dlist->head;
  while(cur!=NULL){
    if(cur->_value==value)
      return cur;
    cur=cur->_next;
  }
  return NULL;
}

//插
// 在pos的前面进行插入
void DListInsert(DListNode *pos, DLDataType value){
 DListNode* node=DListBuyNode(value);
 node->_next=pos;
 node->_prev=pos->_prev;
 pos->_prev->_next=node;
 pos->_prev=node;
}
// 删除pos位置的节点
void DListErase(DListNode *pos){

  pos->_prev->_next=pos->_next;
  pos->_next->_prev=pos->_prev;
  free(pos);
}

void ListRemove(DList * dlist, DLDataType value){
  assert(dlist);

  DListNode* cur=dlist->head;
  while(cur!=NULL){
    if(cur->_value==value)
    DListErase(cur);
    cur=cur->_next;
  }
}

//打印
void DListPrint(const DList *dlist){
  assert(dlist!=NULL);

  DListNode* cur=dlist->head;
  while(cur->_next!=NULL){
    printf("%d<-->",cur->_value);
    cur=cur->_next;
  }
}
