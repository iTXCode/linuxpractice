#include"BinaryHeap.h"


void Test(){
  int array[]={12,34,56,67,4,5,6,8,98,10};
  //int array[]={1,2,9,16,7,15,18,45,37,63,13}; 
  int size=sizeof(array)/sizeof(array[0]);
  Heap heap;
  Print_Heap(array,size);
  Heap_Init(&heap,array,size);
  Print_Heap(heap.array,heap.size);
  Heap_Pop(&heap);
  Print_Heap(heap.array,heap.size);
  Heap_Push(&heap,520);
  Print_Heap(heap.array,heap.size);
  Heap_Sort(heap.array,heap.size);
  Print_Heap(heap.array,heap.size);
}

int main(){
  Test();
  return 0;
}
