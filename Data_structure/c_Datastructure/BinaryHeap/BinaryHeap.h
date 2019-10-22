//二叉堆(又叫堆) 本身逻辑上是一颗完全二叉树
//物理上是一个数组
//作用:找数据中的最值
//二叉堆中任意节点的值大于(小于)左右孩子结点的值
//大堆和小堆
#pragma  once 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<memory.h>
//已知[parent]
//[left]=2*[parent]+1;
//[right]=2*[parent]+2;
//
//已知[child](无论左右)
//[parent]=([child-1])/2
//
//堆的向下调整过程
//要调整的结点下标是[root]
//[root] 左右子树已经满足堆的性质
//1.要调整[root]
typedef struct Hwap{
  int *array;
  int size;
}Heap;

void HeapInit(Heap* heap,int array[],int size);
/*
 array 要调整的数组
 size  调整的数组的个数
 root  要调整的元素的下标
 */
void AdjustDown(int array[],int  size,int root);

 //建立二叉堆的过程
 //时间复杂度: 精确：O(n)
 //粗略 O(nlogn)
 void CreateHeap(int array[],int size);

//插入
//堆的插入，插到堆的最后一个位置,再进行向上调整

 void HeapPush(Heap *heap,int val);

 void AdjustUp(int array[],int size,int child);
   //向上调整
   //array 数组  size 数组的长度   child  要向上调整的结点下标
   
   //停止条件
   //1.比不过  parent
   //2.已经登基
 


//删除
//堆的删除只能删除堆顶元素,删其他位置没有意义
//通常是用堆的最后一个元素覆盖掉堆顶元素
 void HeapPop(Heap* heap);


//返回堆顶元素
int HeapTop(Heap* heap);

void PrintHeap(int array[],int size);

//堆排序：排升序，建大堆
//        排降序，建小堆
//         原因:重新调整回堆的成本更小
//         向下调整(O(logn)) < 建堆（O(n))
//
//选择排序：既可以找到最大的放到最后
//也可以找到最小的放到最前,
//但是堆排序不能找到最小的放到最前,这样会导致
//堆乱序


//堆排序
//升序  建大堆
//这个排序用来排降序
void HeapSort1(int array[],int size);
