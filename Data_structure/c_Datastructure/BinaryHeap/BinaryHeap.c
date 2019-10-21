
#include"BinaryHeap.h"

void HeapInit(Heap* heap,int array[],int size){
  heap->array=(int*)malloc(sizeof(int)*size);
  memcpy(heap,array,sizeof(int)*size); 
  heap->size=size;
}
void AdjustDown(int array[],int  size,int root){
  //判断root 是否是叶子结点
  //因为堆是完全二叉树,所以没有左孩子就一定没有右孩子
  //又因为堆是顺序存储的
  //所以，找到左孩子的下标,如果左孩子的下标越界了则没有右孩子
  while(1){  
    int left=2*root+1;
    if(left>=size){//越界,不能漏掉=
      return ;
      //是叶子结点
    }

    //找到左右孩子中最小的一个
    //这里一定有左孩子，判断是否有右孩子
    int right=2*root+2;
    int min=left;
    if(right<size&&array[right]<array[left]){
      min=right;
    }
    //比较array[min] array[root]大小关系
    if(array[root]<=array[min]){
      return;
    }

    int t=array[root];
    array[root]=array[min];
    array[min]=t;
    //需要继续向下调整,以min 作为结点
    root=min;
  }
}


 //建立二叉堆的过程
 //时间复杂度: 精确：O(n)
 //粗略 O(nlogn)
 //建个小堆
void CreateHeap(int array[],int size);

void PrintHeap(int array[],int size){
  for(int i=0;i<size;i++){
    printf("%d ",array[i]);
  }
}

////插入
////堆的插入，插到堆的最后一个位置,再进行向上调整
//
// void HeapPush(Heap *heap,int val);
//
// void AdjustUp(int array[],int size,int child);
//   //向上调整
//   //array 数组  size 数组的长度   child  要向上调整的结点下标
//   
//   //停止条件
//   //1.比不过  parent
//   //2.已经登基
// 
////删除
////堆的删除只能删除堆顶元素,删其他位置没有意义
////通常是用堆的最后一个元素覆盖掉堆顶元素
// void HeapPop(Heap* heap);
//
//
////返回堆顶元素
//int HeapTop(Heap* heap);
//
