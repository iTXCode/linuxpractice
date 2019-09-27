#include"DLoopList.hpp"

void TestDLoopList(){
  DList<int>  dlist;
  dlist.DListInit(&dlist);
  dlist.DListPushFront(&dlist,5);
  dlist.DListPushFront(&dlist,4);
  dlist.DListPushFront(&dlist,3);
  dlist.DListPushFront(&dlist,2);
  dlist.DListPushFront(&dlist,1);
  dlist.DListPushBack(&dlist,6);
  dlist.DListPrint(&dlist);
  dlist.DListPopBack(&dlist);
  dlist.DListPrint(&dlist);
  dlist.DListPopFront(&dlist);
  dlist.DListPrint(&dlist);
  DListNode<int>* pos=dlist.DListFind(&dlist,4);
  dlist.DListInsertFront(pos,520);
  dlist.DListInsertBack(pos,1314);
  dlist.DListPrint(&dlist);
  dlist.DListErase(pos);
  dlist.DListPrint(&dlist);
}

int main(){
  TestDLoopList();
  return 0;
}
