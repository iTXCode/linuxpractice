#include"BinaryTree.hpp"

void TestTree(){

  Bitree<char> tree;
  tree.BitreeInit(&tree);
  TreeNode<char>* root=tree.getroot();
  tree.PreOrderTravel(root);
  std::cout<<std::endl;
 
}

int main(){
  TestTree();
  return 0;
}
