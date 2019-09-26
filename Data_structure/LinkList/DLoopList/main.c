#include"DList.h"

void TestDList(){
  DList dlist;

  DListInit(&dlist);
  DListPushFront(&dlist,1);
  DListPushBack(&dlist,2);
  DListPushBack(&dlist,3);
  DListPushBack(&dlist,4);
  DListPushBack(&dlist,5);
  DListPrint(&dlist);
  DListPopFront(&dlist);
  DListPrint(&dlist);
  DListPopBack(&dlist);
  DListPrint(&dlist);
  DListNode* node=DListFind(&dlist,3);
  DListInsert(node,520);
  DListPrint(&dlist);
  DListErase(node);
  DListPrint(&dlist);
  bool ret=DListEmpty(&dlist);
  printf("DList is Empty? %d\n",ret);
  DListClear(&dlist);
  
  DListDestory(&dlist);

}

int main(){
  TestDList();
  return 0;
}
