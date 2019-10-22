
#include"BinaryHeap.h"

void HeapInit(Heap* heap,int array[],int size){
  heap->array=(int*)malloc(sizeof(int)*size);
  memcpy(heap->array,array,sizeof(int)*size); 
  heap->size=size;
  CreateHeap(heap->array,size);
}

void Swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
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
    Swap(&array[root],&array[min]);
    //需要继续向下调整,以min 作为结点
    root=min;
  }
}


 //建立二叉堆的过程
 //时间复杂度: 精确：O(n)
 //粗略 O(nlogn)
 //建个小堆
 //建立根节点的时候，其左右子树必须先满足堆的性质
void CreateHeap(int array[],int size){
  for(int i=(size-2)/2;i>=0;i--){
    AdjustDown(array,size,i);
  }
}

void PrintHeap(int array[],int size){
  for(int i=0;i<size;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}

//插入
//堆的插入，插到堆的最后一个位置,再进行向上调整

void HeapPush(Heap *heap,int val){
  heap->array[heap->size++]=val;
  AdjustUp(heap->array,heap->size,heap->size-1);
  
}

void AdjustUp(int array[],int size,int child){
  while(child!=0){
    //此处的终止条件换成parent的时候会造成死循环
    if(child>=size)
      return;
    int parent=(child-1)/2;
    if(array[child]>array[parent])
      return;
    Swap(&array[child],&array[parent]);
    child=parent;
  }
}
   //向上调整
   //array 数组  size 数组的长度   child  要向上调整的结点下标
   
   //停止条件
   //1.比不过  parent
   //2.已经登基
 
//删除
//堆的删除只能删除堆顶元素,删其他位置没有意义
//通常是用堆的最后一个元素覆盖掉堆顶元素
//再对乱序的堆进行重新调整
 void HeapPop(Heap* heap){
  heap->array[0]=heap->array[heap->size-1];
  //此时其左右子树满足堆的性质
  AdjustDown(heap->array,heap->size-1,0);
  heap->size--;
 }


//返回堆顶元素
 int HeapTop(Heap* heap){
   return heap->array[0];
 }
//这个排序用来排降序
void HeapSort1(int array[],int size){
  CreateHeap(array,size);
//i表示被找出的最大的数的个数
  for(int i=0;i<size-1;i++){
    //每次循环,会找出最大的一个数与数组最后一个元素
    //进行交换,将堆的size--,之后将现有的堆进行调整
    //使得它满足堆的性质
        
    int t=array[0];
    array[0]=array[size-i-1];
    array[size-i-1]=t;

    //进行向下调整，数据规模 size-i-1
    AdjustDown(array,size-1-i,0);
  }
}
