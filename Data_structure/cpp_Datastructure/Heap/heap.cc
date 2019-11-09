#include"Heap.hpp"

int main(){
  int array[]={91,3,84,56,56,78,34,65,86,24};
  int size=sizeof(array)/sizeof(array[0]);
  ReHeap<int> heap;
  Heap<int> _Heap;
  heap.HeapInit(&heap,_Heap,array,size);
  heap.PrintHeap(array,size);
  Heap<int>* _heap=heap.getheap();
  heap.PrintHeap(_heap->_array,_heap->_size);
  heap.HeapPush(_heap,10);
  heap.PrintHeap(_heap->_array,_heap->_size);
  printf("%d\n",_heap->_size);//11
  heap.HeapPop(_heap);
  printf("%d\n",_heap->_size);
  heap.PrintHeap(_heap->_array,_heap->_size);
  return 0;
}
