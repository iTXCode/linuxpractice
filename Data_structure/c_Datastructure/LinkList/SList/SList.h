#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


typedef int SLDataType;

typedef struct SLNode{
  SLDataType _value;
  struct SLNode *next;
}SLNode;

typedef struct SList{
  SLNode *first;
}SList;


//初始化
void SListInit(SList*list);

//销毁过程
void SListDestory(SList *list);

//增
//头插
void SListPushFront(SList *list,SLDataType value);
//尾插
void SListpushBack(SList *list, SLDataType value);





//删
//头删
void SListPopFront(SList *list);
//尾删
void SListPopBack(SList *list);

//打印
void SListPrint(SList *list);

//查
SLNode * SListFind(const SList *list, SLDataType value);

//改
void  SlistNodeUpdate(SLNode *node, SLDataType value);

//指定位置插入元素
//1-->2-->3-->NULL

void SListInsertAfter(SLNode *pos, SLDataType value);

//删除给定pos位置后面的结点
void SListEraseAfter(SLNode *pos);

//指定位置pos 前面插入新结点
void SListInsertBefore(SList *list, SLNode *pos, SLDataType value);
