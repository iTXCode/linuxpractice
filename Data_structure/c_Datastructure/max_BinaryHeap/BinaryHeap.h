#pragma once

#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

typedef struct Heap{
  int *array;//定义一个动态申请的空间
  int size;
}Heap;


//初始化堆
void Heap_Init(Heap* heap,int array[],int size);

//创建一个大堆
void Heap_Create(int array[],int size);

//向下调整(建大堆)
void Heap_AdjustDown(int array[],int size,int child);

//增
void Heap_Push(Heap* heap,int val);

//向上调整
void Heap_AdjustUp(int array[],int size,int child);
//删
void Heap_Pop(Heap* heap);
//排序
void  Heap_Sort(int *array,int size);

//打印出堆中的元素
void Print_Heap(int array[],int size);

int  Heap_Top(Heap* heap);
