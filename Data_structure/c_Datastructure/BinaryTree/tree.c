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

  //求二叉树的深度
  int tree_depth=TreeDepth(tree);
  printf("该树的深度为:%d\n",tree_depth);
  int k=0;
  printf("请输入要求的层数:");
  scanf("%d",&k);
  int k_node_num=KNode( tree,k);
  printf("第K层的结点个数为:%d\n",k_node_num);
  //确定二叉树中是否有指定的值存在‘

  TreeNode* find_result=Tree_Value_Find(tree,'D');
  if(find_result==NULL){
    printf("在该二叉树中没有找到指定的值,它的地址为:%p\n",find_result);
  }else{
    printf("在该二叉树中找到了该值:%c 该结点地址为:%p\n",find_result->_value,find_result);
  }

  //层序遍历二叉树

  printf("层序遍历二叉树的结果为:");
  Levelordertravel(tree);
}                             
              
int main(){
  TestTree();
  return 0;
}
