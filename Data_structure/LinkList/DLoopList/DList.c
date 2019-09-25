#include"DList.h"

//申请新的结点node
DListNode*  DListBuyNode(DLDataType value){
  DListNode* node=(DListNode*)malloc(sizeof(DListNode));
  
  node->_value=value;
  node->_prev=NULL;
  node->_next=NULL;
  return node;
}

void DListInit(DList* dlist){
  assert(dlist!=NULL);
  
  DListNode* node=DListBuyNode(0);
  dlist->head=node;
  node->_prev=node->_next=dlist->head;
}
//头插
//
void DListPushFront(DList* dlist,DLDataType value){
 assert(dlist!=NULL);

 DListNode* new_node=DListBuyNode(value);
 new_node->_next=dlist->head;
 new_node->_prev=dlist->head;
 dlist->head->_next=new_node;
 dlist->head->_prev=new_node;
}

//尾插
void DListPushBack(DList* dlist,DLDataType value){
  assert(dlist!=NULL);

  DListNode* new_node=DListBuyNode(value);
  new_node->_prev=dlist->head->_prev;
  dlist->head->_prev->_next=new_node;
  new_node->_next=dlist->head;
  dlist->head->_prev=new_node;
}

void DListPopFront(DList* dlist){
  assert(dlist!=NULL);

  DListNode* cur=dlist->head->_next;
  dlist->head->_next=cur->_next;
  cur->_next->_prev=dlist->head;

  free(cur);
}

//尾删
void DListPopBack(DList* dlist){
  assert(dlist!=NULL);

  DListNode* cur=dlist->head->_prev;
  cur->_prev->_next=dlist->head;
  dlist->head->_prev=cur->_prev;
  free(cur);
}

bool DListEmpty(const DList*dlist){
  assert(dlist!=NULL);
  assert(dlist->head!=NULL);
  if(dlist->head->_next==dlist->head)
    return false;
  else 
    return true;
}


//插
//// 在pos的前面进行插入
void DListInsert(DListNode *pos, DLDataType value){
  DListNode* node=DListBuyNode(value);
  node->_next=pos->_next;
  pos->_next->_prev=node;
  pos->_next=node;
  node->_prev=pos;
}
// 删除pos位置的节点
void DListErase(DListNode *pos){
  pos->_prev->_next=pos->_next;
  pos->_next->_prev=pos->_prev;
  free(pos);
}

void ListRemove(DList * dlist, DLDataType value){
  assert(dlist!=NULL);

  DListNode* cur=dlist->head->_next;
  while(cur!=dlist->head){
    //没写完
    if(cur->_value==value)
    DListErase(cur);
    cur=cur->_next;
  }

}


void DListPrint(const DList* dlist){
  assert(dlist!=NULL);

  DListNode* cur=dlist->head->_next;
  while(cur!=dlist->head){
    printf("%d<-->",cur->_value);
    cur=cur->_next;
  }
  printf("\n");
}
