#include"BinaryTree.hpp"


void TestTree(){
  TreeNode<char> tree;

  char str[]="ABD##E##CF##G##";
  tree.BinaryTreeInit(&tree);
  tree.PreCreate(&tree,str);
  tree.PostOrderTravel(&tree);
  tree.InOrderTravel(&tree);
  tree.PostOrderTravel(&tree);
  //tree.LevelTravel(&tree);
}
int main(){
  TestTree();
  return 0;
}
