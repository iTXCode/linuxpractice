#include"BinaryTree.hpp"

void TestTree(){
  Bitree<char> tree;

  std::string s="ABD##E##CF##G##";
  tree.PreCreate(tree,&s);
}


int main(){
  TestTree();
  return 0;
}
