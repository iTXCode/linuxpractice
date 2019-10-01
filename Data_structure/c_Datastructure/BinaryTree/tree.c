#include"BinaryTree.h"


void TestTree(){ 
  Bitree tree;   
  printf("请输入建立二叉树的结点值:");
  CreateTree(&tree);
  printf("先序遍历:");
  PreOrderTravel(tree);
  printf("\n中序遍历:");
  InOrderTravel(tree);   
  printf("\n后序遍历:");
  PostOrderTravel(tree);
  printf("\n");
  printf("该树的叶子结点:");
  PreOrder(tree);
  printf("\n");
  printf("叶子结点个数:%d\n",PostOrder(tree));
  printf("叶子结点个数:%d\n",Leaf(tree));
}                             
              
int main(){
  TestTree();
  return 0;
}
