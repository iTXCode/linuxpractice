#include<iostream>
#include<malloc.h>

template <class T>
  struct TreeNode{
  TreeNode<T>* _left;
  TreeNode<T>* _right;
  T _val;
};

template <class T>
class  Bitree{
public:
  Bitree(){
    _root=NULL;
  }


  TreeNode<T>** CreateTree(TreeNode<T>** root){
    T val;
    std::cin>>val;
    if(val=='#'){
      *root=NULL;
    }
    else{
      if(*root==NULL){
        (*root)=(TreeNode<T>*)malloc(sizeof(TreeNode<T>));
        (*root)->_left=(*root)->_right=NULL;
      }
      (*root)->_val=val;
      CreateTree(&(*root)->_left);
      CreateTree(&(*root)->_right);
    }
    return root;
  }
void   BitreeInit(Bitree* root){
    TreeNode<T>** t_root=CreateTree(&(root->_root));
    root->_root=*t_root;
  }

void PreOrderTravel(TreeNode<T>*  root){
  if(root==NULL){
    return;
  }
  std::cout<<root->_val;
  PreOrderTravel(root->_left);
  PreOrderTravel(root->_right);
}
TreeNode<T>* getroot(){
  return _root;
}
private:
  TreeNode<T>* _root;
};
