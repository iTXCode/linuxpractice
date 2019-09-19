#include"SList.h"



void TestSLNode(){
  SList slist;
  SListInit(&slist);
  SListPushFront(&slist,1);
  SListPushFront(&slist,9);
  //9  1
  SListPrint(&slist);
  SListPushFront(&slist,8);
  SListPrint(&slist);
  // 8 9 1
  SListPushFront(&slist,5);
  SListPrint(&slist);
  // 5 8 9 1
  SListpushBack(&slist,4);
  SListpushBack(&slist,3);
  SListpushBack(&slist,2);
  SListpushBack(&slist,100);
  //5 8 9 1 4 3 2 100
  SListPopFront(&slist);
  // 8 9 1 4 3 2 100
  SListPopBack(&slist);
  SListPrint(&slist);
  // 8  9 1 4 3 2 
  SListPopFront(&slist);
  //9  1 4 3 2 
  SListPrint(&slist);
  SLNode* node=SListFind(&slist,3);
  SListEraseAfter(node);
  // 9  1 4 3 
  SListInsertAfter(node,520);
  // 9 1 4 3 520
  SListPrint(&slist);
  SListEraseAfter(node);
  // 9 1 4 3 
  SListInsertBefore(&slist,node,1314);
  // 9 1 4   1314 3 
  SListPrint(&slist);
}

int  main()
{
  TestSLNode();
  return 0;
}
