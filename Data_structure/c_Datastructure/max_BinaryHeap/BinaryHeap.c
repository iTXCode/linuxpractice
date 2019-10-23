#include"BinaryHeap.h"

//初始化堆
void Heap_Init(Heap* heap,int array[],int size){
  heap->array=(int*)malloc(sizeof(int)*size);
  memcpy(heap->array,array,sizeof(int)*size);
  heap->size=size;
  Heap_Create(heap->array,heap->size);
}


void Swap(int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}


//向下调整(建大堆)
void Heap_AdjustDown(int array[],int size,int child){
  //向下调整，建大堆的过程
  while(1){   
    int left=2*child+1;
    if(left>=size){
      //检查所给的目标结点左孩子下标是否合法
      return;
    }

    int max=left;
    int right=2*child+2;
    if(right<size&& array[right]>array[left]){
      max=right;
    }
    if(array[child]>=array[max]){
      return;
    }
    Swap(&array[max],&array[child]);
    child=max; }
}


//创建一个大堆
void Heap_Create(int array[],int size){
  for(int i=(size-2)/2;i>=0;i--){
    Heap_AdjustDown(array,size,i);
  }
}


//向上调整
void Heap_AdjustUp(int array[],int size,int child){
  //边界条件:1.要调整的下标不为0
  while(child!=0){
    
    if(child>size){
      return ;
    }
    int parent=(child-1)/2;
    if(array[parent]>=array[child]){
      return ;
    }
    Swap(&array[parent],&array[child]);
    child=parent;
  }
}

//增
void Heap_Push(Heap* heap,int val){
  heap->array[heap->size++]=val;
  Heap_AdjustUp(heap->array,heap->size,heap->size-1);
}


//删
void Heap_Pop(Heap* heap){
  //删除要进行尾删,将第一个结点和最后一个结点的值
  //进行交换，然后再将整个堆进行调整
  Swap(&heap->array[0],&heap->array[heap->size-1]);
  heap->size--;
  Heap_AdjustDown(heap->array,heap->size,0);
}
//排序
void  Heap_Sort(int array[],int size){
  //按找升序排列
  Heap_Create(array,size);
  for(int i=0;i<size;i++){
    Swap(&array[0],&array[size-1-i]);
    Heap_AdjustDown(array,size-1-i,0);
  }
}

int  Heap_Top(Heap* heap){
  return heap->array[0];
}
//打印出堆中的元素
void Print_Heap(int array[],int size){
  for(int i=0;i<size;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}

