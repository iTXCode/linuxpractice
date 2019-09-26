#include"SList.hpp"

void TestSList(){
  SList slist;
  slist.SLNodeInit(&slist);
  slist.SListFrontPush(&slist,1);
  slist.SListFrontPush(&slist,2);
  slist.SListFrontPush(&slist,5);
  slist.SListFrontPush(&slist,6);
  slist.SListFrontPush(&slist,7);
  slist.SListBackPush(&slist,3);
  slist.SListBackPush(&slist,4);
  slist.SListPrint(&slist);

  slist.SListPopBack(&slist);
  slist.SListPopFront(&slist);
  slist.SListPrint(&slist);

  SLNode* node=slist.SListFind(&slist,1);
  
  slist.SListInsertAfter(node,4);
  slist.SListPrint(&slist);
  slist.SListInsertBefore(&slist,node,520);
  slist.SListPrint(&slist);
  slist.SListEraseAfter(node);
  slist.SListPrint(&slist);
}

int main(){
  TestSList();
  return 0;
}
