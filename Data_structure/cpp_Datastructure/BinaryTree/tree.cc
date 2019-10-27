#include"BinaryTree.hpp"


void TestTree(){
  TreeNode<char> tree;

  char str[]="ABD##E##CF##G##";
  tree.PreCreate(&tree,str);

}
int main(){
  TestTree();
  return 0;
}
