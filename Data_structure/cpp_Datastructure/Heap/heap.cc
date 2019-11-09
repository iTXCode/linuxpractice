#include"Heap.hpp"

int main(){
  int array[]={91,3,84,56,56,78,34,65,86,24};
  int size=sizeof(array)/sizeof(array[0]);
  ReHeap<int> heap;
  Heap<int> _Heap;
  Heap<int>* _heap=heap.getheap();
  heap.HeapInit(&heap,_Heap,array,size);
  heap.PrintHeap(_heap->_array,_heap->_size);
  return 0;
}
