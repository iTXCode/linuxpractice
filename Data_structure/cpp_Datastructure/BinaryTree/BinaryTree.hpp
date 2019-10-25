#include<iostream>
#include<assert.h>
#include<string>

template <class T>
//定义二叉树结点结构
struct TreeNode{
  TreeNode(const T val){
   _left=NULL;
   _right=NULL;
   _val=val;
  }
 TreeNode<T>*  _left;
 TreeNode<T>*  _right;
 T  _val;
};

template <class T>
class Bitree{ 
  typedef TreeNode<T>* pNode;
  typedef TreeNode<T> Node;
public:
Bitree(){
  _root=NULL;
}
  //先序遍历创建二叉树的
void PreCreate(Bitree tree,std::string* s){
 assert(tree->_root!=NULL);
 std::string str= *s;
 if(str=="#")
   tree->_root=NULL;
 else{
  PreCreate(tree->_root->_left,++s);
  PreCreate(tree->_root->_right,++s);
}
}
private: 
  TreeNode<T>* _root;
};
