#include"Heap.hpp"

void  TestHeap(){
  int array[]={91,3,84,56,56,78,34,65,86,24};
  int size=sizeof(array)/sizeof(array[0]);
  Heap<int> heap;
  heap.HeapInit(&heap,array,size);
  heap.PrintHeap(&heap);
  heap.HeapPop(&heap);
  heap.PrintHeap(&heap);
  printf("请输入您要插入的值:");
  int value=0;
  std::cin>>value;
  heap.HeapPush(&heap,value);
  heap.PrintHeap(&heap);
  std::cout<<"请输入您要查找的值:";
  std::cin>>value;
  int ret=heap.HeapFind(&heap,value);
  if(ret==1){
    std::cout<<"你要找的值在堆序列中!"<<std::endl;
  }else{
    std::cout<<"您要找的值不在堆序列中!"<<std::endl;
  }
  

  printf("请输入您要修改的值:");
  std::cin>>value;
  
  heap.HeapModify(&heap,value);
  heap.PrintHeap(&heap);
  //排降序
  heap.SortUp(&heap,size);
  heap.PrintHeap(&heap);



}


int main(){
  TestHeap();
  return 0;
}
