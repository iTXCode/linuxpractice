#include"BinaryTree.hpp"

void TestTree(){

  Bitree<char> tree;
  tree.BitreeInit(&tree);
  TreeNode<char>* root=tree.getroot();
  std::cout<<"前序遍历:";
  tree.PreOrderTravel(root);
  std::cout<<std::endl;
  std::cout<<"中序遍历:";
  tree.InOrderTravel(root);
  std::cout<<std::endl;
  std::cout<<"后序遍历:";
  tree.PostOrderTravel(root);
  std::cout<<std::endl;
  std::cout<<"层序遍历:";
  tree.LevelTravel(root);
  std::cout<<std::endl;
  std::cout<<"请输入你要查找的结点的值:";
  char val;
  std::cin>>val;
  TreeNode<char>* result_find=tree.Tree_Value_Find(root,val);
  if(result_find!=NULL)
  std::cout<<result_find->_val<<std::endl;
  else{
    std::cout<<result_find<<std::endl;
  }
  std::cout<<"该树的高度为:"<<tree.Tree_Height(root)<<std::endl;
  std::cout<<"该树中的叶子结点分别为:";
  tree.Tree_Left(root);
  std::cout<<std::endl;

  std::cout<<"该树中叶子结点的个数为:"<<tree.Left_Num(root)<<std::endl;
  
  std::cout<<"请输入需要求的层数K:";
  int k;
  std::cin>>k;
  std::cout<<"该二叉树中第K层的结点值为:";

  tree.Level_K_Value(root,k);
  std::cout<<std::endl;

  std::cout<<"第K层结点的个数为:"<<tree.K_LevelNum(root,k)<<std::endl;
}

int main(){
  TestTree();
  return 0;
}
