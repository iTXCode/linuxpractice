#include"SList.h"

void TestSLNode(){
  SList slist;
  SListInit(&slist);
  SListPushFront(&slist,1);
  SListPushFront(&slist,9);
  SListPushFront(&slist,8);
  SListPushFront(&slist,5);
  SListPrint(&slist);
  SListpushBack(&slist,4);
  SListpushBack(&slist,3);
  SListpushBack(&slist,2);
  SListpushBack(&slist,100);
  SListPopFront(&slist);
  SListPopBack(&slist);
  SListPopFront(&slist);

}

int  main()
{
  TestSLNode();
  return 0;
}
