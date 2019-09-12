#pragma once 

#include<iostream>


enum COLOR{
  RED,BLACK
};
template <class T>

struct RBTreeNode{
  RBTreeNode(const T& data=T(),COLOR color=RED)
    :_pLeft(nullptr)
     ,_pRight(nullptr)
     ,_pParent(nullptr)
     ,_data(data)
     ,_color(color)
  {}
  RBTreeNode<T>* _pLeft;
  RBTreeNode<T>* _pRight;
  RBTreeNode<T>* _pParent;
  T _data;
  COLOR _color;

};

template  <class T>

class RBTree{
public:
  typedef RBTreeNode<T> Node;
  RBTree()
  {
    _pHead=new Node;
    _pHead->_pLeft=_pHead;
    _pHead->_pRight=_pHead;
  }

  bool Insert(const T&data){
    //首先判断红黑树是否为空,判断头结点的双亲指针域是否为空
    //若为空,则其为空树
   Node* &pRoot=GetRoot();
   if(nullptr==pRoot){
     pRoot=new Node(data);
     pRoot->_pParent=_pHead;
     _pHead->pLeft=pRoot;
     _pHead->_pRight=pRoot;
     return true;
   }
   else{
     //1.按照二叉搜索树的性质，
     //找到待插入节点再红黑树中的位置
     Node* pCur=pRoot;
     Node* pParent=nullptr;
     while(pCur){
       pParent=pCur;
       if(data<pCur->_data)
         pCur=pCur->_pLeft;
       else if(data>pCur->_data)
         pCur=pCur->_pRight;
       else 
         return false;
     }
     //插入新的节点
     pCur=new Node(data);
     if(data<pParent->_data)
       pParent->_pLeft=pCur;
     else 
       pParent->_pRight=pCur;
     pCur->_pParent=pParent;

     //检测:是否新节点插入后,是否有连在一起的红色节点
     if(RED==pParent->_color){
       
     }
   }
   pRoot->_color=BLACK;
   _pHead->_pLeft=LeftMost();
   _pHead->_pRight=RightMost();
  }

  Node* LeftMost(){
    Node* pRoot=GetRoot();
    if(nullptr==pRoot){
        return _pHead;
    }
    Node* pCur=pRoot;
    while(pCur->_pLeft){
      pCur=pCur->_pLeft;
    }
    return pCur;
  }

  Node* RightMost(){
    Node* pRoot=GetRoot();
    if(nullptr==pRoot){
        return _pHead;
    }
    Node* pCur=pRoot;
    while(pCur->_pRight){
      pCur=pCur->_pRight;
    }
    return pCur;
  }


private:
  Node* _pHead;
  Node* &GetRoot(){
    return _pHead->_pParent;
  }
};
