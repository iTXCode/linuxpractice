#include"DList.hpp"

void TestDList(){
  DList<int>  dlist;
  dlist.DListInit(&dlist);
  dlist.DListPushFront(&dlist,1);
  dlist.DListPushFront(&dlist,2);
  dlist.DListPushFront(&dlist,4);
  dlist.DListPushFront(&dlist,5);
  dlist.DListPushBack(&dlist,3);
  dlist.DListPrint(&dlist);
  dlist.DListPopFront(&dlist);
  dlist.DListPopBack(&dlist);
  dlist.DListPrint(&dlist);
  dlist.DListPushBack(&dlist,5);
  dlist.DListPrint(&dlist);
  DListNode<int>* pos=dlist.DListFind(&dlist,5);
  dlist.DListInsertBack(&dlist,pos,6);
  dlist.DListInsertFront(&dlist,pos,7);
  dlist.DListPrint(&dlist);
  dlist.DListPosUpdate(pos,520);
  dlist.DListPrint(&dlist);
  dlist.DListEraseAfter(pos);
  dlist.DListPrint(&dlist);
  dlist.DListClear(&dlist);
  dlist.DListDestory(&dlist);

}

int main(){
  TestDList();
  return 0;
}
