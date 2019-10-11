#include<iostream>

enum COLOR{RED,BLACK};

template <class T>

struct RBTreeNode{
public:
  RBTreeNode(const T&data=T(),COLOR color=RED)
  :_pLeft(nullptr)
  ,_pRight(nullptr)
   ,_pParent(nullptr)
   ,_data(data)
   ,_color(color) 
  {

  }
private:
  RBTreeNode<T>* _pLeft;
  RBTreeNode<T>* _pRight;
  RBTreeNode<T>* _pParent;
  T _data;
  COLOR _color;
};

template <class T>

class RBTree{
public:
  typedef RBTreeNode<T>   Node;
  typedef Node*  pNode;
public:
  bool Insert(const T& data){
    //首先判断是否为空树 
    pNode &pRoot=GetRoot();
    if(nullptr==pRoot){
      pRoot=new Node(data);
      pRoot->_pParent=_pHead;
      _pHead->_pLeft=pRoot;
      _pHead->_pRight=pRoot;
    }
    else{
      pNode pCur=pRoot;
      pNode pParent=nullptr;
      while(pCur){
        pParent=pCur;
        //每次更新当前节点的父亲节点,本轮循环中和pCur指向同一个节点
        //下一轮中指向的就是要插入节点的父亲节点
        if(data<pCur->_data){
          pCur=pCur->_pLeft;
        }else if(data>pCur->_data){
          pCur=pCur->_pRight;
        }else{
          return false;
        }
      }
      //找到接的话就进行插入操作
      pCur=new Node(data);
      if(data<pParent->_data){
        pParent->_pLeft=pCur;
      }
      else{
        pParent->_pRight=pCur;
      }
      pCur->_pParent=pParent;
      }
    }
  
private:
  pNode _pHead;
  pNode GetRoot(){
    return _pHead->_pParent;
    //返回根节点
  }

};
