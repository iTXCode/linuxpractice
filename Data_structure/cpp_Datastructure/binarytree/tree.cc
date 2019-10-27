#include"BinaryTree.hpp"

void TestTree(){
  Bitree<char> tree;
  TreeNode<char> root;
  tree.BitreeInit(&tree,&root);
  tree.PreCreate(&root);
  tree.PreOrderTravel(&root); 
}

int main(){
  TestTree();
  return 0;
}
