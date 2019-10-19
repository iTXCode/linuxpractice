#include<iostream>
#include<assert.h>

template <class T>

//定义二叉树结点结构
struct TreeNode{
  TreeNode(const T val){
   _left=NULL;
   _right=NULL;
   _val=val;
  }
 TreeNode*  _left;
 TreeNode*  _right;
 T _val;
};

template <class T>
class Bitree{
public:
  Bitree()
  {_root=NULL;}
  //先序遍历创建二叉树的
  void PreCreate(Bitree<T> root){

  }
private:
  TreeNode<T>* _root;
};
