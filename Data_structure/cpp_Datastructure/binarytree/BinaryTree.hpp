#include<iostream>
#include<malloc.h>


template <class T>
struct TreeNode{
  TreeNode(const T val=T())
  {
    _left=_right=NULL;
    _val=val;
  }
  TreeNode<T>* _left;
  TreeNode<T>* _right;
  T _val;
};

template <class T>
class Bitree{
public:
  Bitree(){
    _root=NULL;
  }

  void BitreeInit(Bitree<T> *tree,TreeNode<T>*root ){
    tree->_root=root;
  }

  void PreCreate(TreeNode<T>* root){
    T val;
    std::cin>>val;
    if(val==' '){
      root=NULL;
    }else{
      if(root==NULL){
        root=new TreeNode<T>(val);
      }
      PreCreate(root->_left);
      PreCreate(root->_right);
    }
  }

  void PreOrderTravel(TreeNode<T>* root){
    if(root==NULL)
      return;
    std::cout<<root->_val<<" ";
    PreOrderTravel(root->_left);
    PreOrderTravel(root->_right);
  }

private:
TreeNode<T>* _root;
};



