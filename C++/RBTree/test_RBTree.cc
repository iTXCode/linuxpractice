#include<iostream>
#include"RBTree.h"

using namespace std;


void Test(){
  int array[]={16,3,7,11,9,26,18,14,15};
  RBTree<int> t;
  for(auto e:array)
    t.Insert(e);
  cout<<"先序遍历:";
  t.PreOrder();
  cout<<endl;
  cout<<"中序遍历:";
  t.InOrder();
  cout<<endl;
  cout<<"后序遍历:";
  t.TailOrder();
  cout<<endl;
  if(t.IsValidRBTree()){
    cout<<"t 是一课红黑树"<<endl;
  }else{
    cout<<"t 不是一颗红黑树"<<endl;
  }
  
}

int main(){
  Test();
  return 0;
}
