#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int DLDataType;

typedef struct DListNode{
  DLDataType _value;
  struct DListNode* _prev;
  struct DListNode* _next;
}DListNode;


typedef struct DList{
 DListNode* head;
}DList;

void  DListInit(DList* dlist);

void DListClear(DList* dlist);

void DListDestory(DList* dlist);

void DListPushFront(DList* dlist,DLDataType value);

void DListPushBack(DList* dlist,DLDataType value);

void DListPopFront(DList* dlist);

void DListPopBack(DList* dlist);

bool DListEmpty(const DList* dlist);

DListNode* DListFind(const DList *dlist,DLDataType value);

DListNode* DListBuyNode(DLDataType value);

//插
//// 在pos的前面进行插入
void DListInsert(DListNode *pos, DLDataType value);
// 删除pos位置的节点
void DListErase(DListNode *pos);

void ListRemove(DList * dlsit, DLDataType value);

//打印
void DListPrint(const DList *dlist);

