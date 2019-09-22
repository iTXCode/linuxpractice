#include"SList.hpp"



void TestSList1(){
  SList<int> slist1;
  slist1.SListInit(&slist1);
  slist1.SListPushFront(&slist1,1);
  slist1.SListPushFront(&slist1,2);
  slist1.SListPushFront(&slist1,3);
  slist1.SListPushFront(&slist1,4);
  slist1.SListPrint(&slist1);
  slist1.SListpushBack(&slist1,4);
  slist1.SListpushBack(&slist1,3);
  slist1.SListpushBack(&slist1,2);
  slist1.SListpushBack(&slist1,1);
  slist1.SListPrint(&slist1);
  slist1.SListPopFront(&slist1);
  slist1.SListPopBack(&slist1);
  slist1.SListPrint(&slist1);

  SLNode<int>* node=slist1.SListFind(&slist1,3);
  slist1.SListNodeUpdate(node,520);
  slist1.SListPrint(&slist1);
  slist1.SListInsertAfter(node,1314);
  slist1.SListPrint(&slist1);
  slist1.SListInsertBefore(&slist1,node,13);
  slist1.SListPrint(&slist1);
  slist1.SListEraseAfter(node);
  slist1.SListPrint(&slist1);
}

int main(){
  TestSList1();
  return  0;
}
