#include"DList.h"

void TestDlist(){
  DList dlist;
  DListInit(&dlist);
  DListPushFront(&dlist,1);
  DListPrint(&dlist);
  DListPushFront(&dlist,2);
  DListPrint(&dlist);
  DListPushFront(&dlist,3);
  DListPrint(&dlist);
  DListPushFront(&dlist,4);
  DListPrint(&dlist);
  DListPushBack(&dlist,1);
  DListPushBack(&dlist,2);
  DListPushBack(&dlist,3);
  DListPushBack(&dlist,4);
  DListPrint(&dlist);
  DListPopBack(&dlist);
  DListPrint(&dlist);
  DListPopFront(&dlist);
  DListNode* node=DListFind(&dlist,2);
  
  DListInsert(node,520);
  DListPrint(&dlist);
  ListRemove(&dlist,3);
  DListPrint(&dlist);
  DListErase(node);
  DListPrint(&dlist);
  DListClear(&dlist);
  DListPrint(&dlist);//结果为空
  
}


int main(){
  TestDlist();
  return 0;
}
