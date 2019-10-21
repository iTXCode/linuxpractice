#include"BinaryHeap.h"

void TestMinHeap(){
  int array[]={23,24,67,88,1,2,4};
  int size=sizeof(array)/sizeof(array[0]);
  PrintHeap(array,size);
  AdjustDown(array,size,0);
  PrintHeap(array,size);
}

int main(){
  TestMinHeap();
  return 0;
}
