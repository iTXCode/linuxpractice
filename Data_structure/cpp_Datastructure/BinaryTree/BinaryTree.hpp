#include<iostream>
#include<assert.h>
#include<string>
#include<malloc.h>

template <class T>

class TreeNode{
public:
  typedef TreeNode<T>* Bitree;
  typedef TreeNode<T> Node;
public:
  TreeNode(const T  val=T()){
    _left=NULL;
    _right=NULL;
    _val=val;
  }

  void PreCreate(Bitree root,const char *str){
    if(*str=='#'){
      root=NULL;
    }else{
      root=(Bitree)malloc(sizeof(Node));
      root->_val=*str;
      PreCreate(root->_left,str++);
      PreCreate(root->_right,str++);
    }
  }
private:
  TreeNode<T>* _left;
  TreeNode<T>* _right;
  T _val;
};




