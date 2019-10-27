#include"BinaryTree.hpp"


void TestTree(){
  TreeNode<char> tree;
  TreeNode<char>* root=&tree; 
  char str[]="ABD##E##CF##G##";

  tree.PreCreate(&root,str);
  tree.PostOrderTravel(&tree);
  tree.InOrderTravel(&tree);
  tree.PostOrderTravel(&tree);
  //tree.LevelTravel(&tree);
}
int main(){
  TestTree();
  return 0;
}
