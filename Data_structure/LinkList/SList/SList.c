#include"SList.h"


//初始化
void SListInit(SList*list){
  assert(list!=NULL);
  list->first=NULL;
}

//销毁过程(不太熟练)
void SListDestory(SList *list){
  assert(list!=NULL);
  SLNode* cur=list->first;
  SLNode *next=NULL;
  while(cur!=NULL){
   next=cur->next;
   free(cur);
   cur=next;
  }
  list->first=NULL;
}

//增
//头插
void SListPushFront(SList *list,SLDataType value){
  assert(list!=NULL);
  SLNode* new_node=(SLNode*)malloc(sizeof(SLNode));
  new_node->_value=value;
  new_node->next=list->first->next;
  list->first=new_node;
}


//尾插
void SListpushBack(SList *list, SLDataType value){
  assert(list!=NULL);
  //寻找尾部
  SLNode* cur=list->first;
  SLNode* new_node=(SLNode *)malloc(sizeof(SLNode));
  while(cur->next!=NULL){
    cur=cur->next;
  }
  new_node->_value=value;
  new_node->next=cur->next;
  cur->next=new_node;
}
//删
//头删

void SListPopFront(SList *list){
assert(list!=NULL);    //保证链表存在
assert(list->first!=NULL);  //保证链表不为空

SLNode *tmp=list->first;
list->first=list->first->next;
free(tmp); 
}

//尾删
void SListPopBack(SList *list){
  assert(list!=NULL);
  assert(list->first!=NULL);
  SLNode *cur=list->first;
  SLNode *tmp=NULL;
  while(cur->next!=NULL){
    tmp=cur;
    cur=cur->next;
  }
  tmp=cur->next;
  free(tmp);
  cur->next=NULL;
}

//打印
void SListPrint(SList *list){
  assert(list!=NULL);

  SLNode *cur=list->first;
  while(cur!=NULL){
    printf("%d  ",list->first->_value);
    cur=cur->next;
  }
  printf("\n");
}

////查
//SLNode * SListFind(const SList *list, SLDataType value){
//
//}
//
////改
//void  SlistNodeUpdate(SLNode *node, SLDataType value);
//
////指定位置插入元素
////1-->2-->3-->NULL
//
//void SListInsertAfter(SLNode *pos, SLDataType value);
//
////删除给定pos位置后面的结点
//void SListEraseAfter(SLNode *pos);
//
////指定位置pos 前面插入新结点
//void SListInsertBefore(SList *list, SLNode *pos, SLDataType value);
