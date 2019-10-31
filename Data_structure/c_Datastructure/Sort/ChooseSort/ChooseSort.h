//选择排序
//1.堆排序
//2.
//3.


//堆排序
//时间复杂度:
//


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>


typedef struct Heap{
  int *array;
  int size;
}Heap;




void PrintArray(int array[],int size){
  for(int i=0;i<size;i++)
    printf("%d ",array[i]);
  printf("\n");
}


void Swap(int* a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
//直接选择排序
//选最小的数
//时间复杂度:O(n^2)
//不稳定
//排升序
void SelectSort(int array[],int size){
 
  for(int i=0;i<size;i++){
    int min=i;
    for(int j=i;j<size;j++){
      if(array[min]>array[j]){
        min=j;
      }
    }
    //内循环负责将最小元素的下标找到
    Swap(array+min,array+i);
    //外层循环负责将最小元素与指定元素进行交换
  } 
}

//排降序
void  Down_SelectSort(int array[],int size){
 
  for(int i=0;i<size;i++){
    int min=i;
    for(int j=i;j<size;j++){
      if(array[min]<array[j]){
        min=j;
      }
    }
    //内循环负责将最大元素的下标找到
    Swap(array+min,array+i);
    //外层循环负责将最大元素与指定元素进行交换
  } 
}

//进阶版
//一次排序过程中既找最大的也找最小的
void Max_Min_SelectSort(int array[],int size){
    int min_Space=0;
    int max_Space=size-1;

    while(min_Space<max_Space){
      //此处的相等的情况是数组中只有一个数
      int min=min_Space;//记录最小元素的下标
      int max=max_Space;//记录最大元素的下标
      for(int i=min_Space+1;i<=max_Space;i++){
        if(array[i]>array[max_Space]){
          max =i;
        }
        if(array[i]<array[min_Space]){
          min=i;
        }
      }
      if(min==min_Space)
        continue;
      Swap(array+min,array+min_Space);
      if(min_Space==max){
        max=min;
      }
      Swap(array+max,array+max_Space);

      min_Space++;//不短更新最小值所在的空间下标
      max_Space--;//不断更新最大值所在的空间下标
    }

}


void Adjust_Down(int *array,int size,int root){

  while(1){
    int left=2*root+1;
    if(left>=size){
      return;
    }
     
    int max=left;
    int right=2*root+2;
    if(right<size&&array[left]<array[right]){
      max=right;
    }
    if(array[max]<=array[root]){
        return;
    }
    Swap(array+max,array+root);
    root=max;
  }

}


void CreateHeap(int array[],int size){
  for(int i=(size-2)/2;i>=0;i--){
    Adjust_Down(array,size,i);
  } 
}


void HeapInit(Heap *heap,int *array,int size){
  heap->array =(int *)malloc(sizeof(Heap)*size);
  heap->size=size;
  memcpy(heap->array,array,sizeof(int)*size);
  CreateHeap(heap->array,heap->size);
}



//堆排序
//时间复杂度O(n*logn)
//空间复杂度:O(1)
//不稳定
void HeapSort(int array[],int size){
  //建大堆  
  for(int i=0;i<size-1;i++){
    Swap(&array[0],&array[size-1-i]);
    //向下调整
    Adjust_Down(array,size-1-i,0);
  }
}

void TestSort(){
  int array[]={2,4,6,8,1,3,5,7,9,0,52};
  int size=sizeof(array)/sizeof(array[0]);
  SelectSort(array,size);
  printf("选择排序排升序:");
  PrintArray(array,size);
  Down_SelectSort(array,size);
  printf("选择排序派降序:");
  PrintArray(array,size);
  printf("进阶版排序结果:");
  Max_Min_SelectSort(array,size);
  PrintArray(array,size);
  Heap heap;
  HeapInit(&heap,array,size);
  PrintArray(heap.array,heap.size);
  HeapSort(heap.array,heap.size);
  PrintArray(heap.array,heap.size);
}
