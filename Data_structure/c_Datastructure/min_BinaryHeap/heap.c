#include"BinaryHeap.h"

void TestMinHeap(){
  //int array[]={23,24,67,88,1,2,4};
  int array[]={27,15,19,18,28,34,65,49,25,37};
  int size=sizeof(array)/sizeof(array[0]);
  CreateHeap(array,size);
  PrintHeap(array,size);
}

void TestHeap(){
  Heap heap;
  int array[]={23,24,67,88,1,2,4};
  int size=sizeof(array)/sizeof(array[0]);
  HeapInit(&heap,array,size);
  PrintHeap(heap.array,heap.size);
  HeapPop(&heap);
  PrintHeap(heap.array,heap.size);
  HeapPush(&heap,520);
  PrintHeap(heap.array,heap.size);
  HeapSort1(heap.array,heap.size);
  PrintHeap(heap.array,heap.size);
  HeapSort2(heap.array,heap.size);
  PrintHeap(heap.array,heap.size);
}

int main(){
  TestHeap();
  return 0;
}
