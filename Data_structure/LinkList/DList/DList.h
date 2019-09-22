#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLDataType;

typedef struct DListNode{
  DLDataType _value;      //头结点中的value没有意义
  struct  DListNode* _prev;
  struct  DListNode* _next;
}DListNode;

typedef struct DList{
  DListNode* head;  //表示链表中的头节点 
} DList;


//初始化
void DListInit(DList *dlist);

//销毁
//1.清空链表
void DListClear(DList *dlist);
//2.彻底的清空链表，彻底销毁
void DListDestory(DList *dlist);


//申请空间的函数
DListNode * DListBuyNode(DLDataType value);

//增
//头插
void  DListPushFront(DList *dlist,DLDataType value);

//尾插
void DListPushBack(DList *dlist, DLDataType value);


//删
//头删
void DListPopFront(DList *dlist,DLDataType value);
//尾删
void DListPopBack(DList *dlist, DLDataType value);


//查找

DListNode * DListFind(DList *dlist,DLDataType value);

//插
// 在pos的前面进行插入
void DListInsert(DListNode *pos, DLDataType value);
// 删除pos位置的节点
void DListErase(DListNode *pos);

void ListRemove(DList * dlsit, DLDataType value);

//打印
void DListPrint(const DList *dlist);
