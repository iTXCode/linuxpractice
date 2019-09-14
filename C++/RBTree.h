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
    //只有一个节点的时候,该节点和头结点
    //建立起联系,让整个树完整的体现
  }

  bool Insert(const T&data){
    //首先判断红黑树是否为空,判断头结点的双亲指针域是否为空
    //若为空,则其为空树
   Node* &pRoot=GetRoot();
   if(nullptr==pRoot){
     //处理只有头结点,没有根节点的情况
     //空树的处理方式
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
       //红黑树不允许存在节点数据相同的情况
     }
     //插入新的节点,不指明颜色即为红色
     pCur=new Node(data);
     if(data<pParent->_data)
       pParent->_pLeft=pCur;
     else 
       pParent->_pRight=pCur;
     pCur->_pParent=pParent;//更新插入节点的双亲节点
     
     //检测:新节点插入后,是否有连在一起的红色节点
     while(pParent!=_pHead && RED==pParent->_color){         
         //【情况一】:要插入位置的父亲节点为红色
         //祖父为根节点的情况,
         //插入的节点若为黑色,该路径上就多了一个黑色节点
         //(只将双亲节点给成黑色也会造成这种情况)
         //需要将双亲节点和叔叔节点同事给成黑色且插入的节点为红色节点

         //若祖父节点不是根节点的话,上述改动方式会使这两条路径相比
         //同地位的路径多出了一个黑色节点,所以需要让这两条路径少一个黑色节点
         //方法:将祖父节点变成红色的节点
         //继续监测祖父节点的双亲节点


         //【情况二】:cur、p是红色 g是黑色 u:不存在||存在&黑色
         //u:不存在,cur 一定为新插入的节点
         //判断的依据:如果cur不是新插入的节点,那么两个红节点就连接到一起了
         //
         //u:存在&黑色 cur一定不是新插入的节点&以前一定为黑色
         //判断依据:g、u都为黑色,g右子树上有两个黑节点
         //而p、cur都为红的话,g左子树上只有一个黑节点(不满足红黑树性质)
         //所以cur必然是黑色调整过来的,此时需要调整整个红黑树了
         //cur变红的原因是其子树中插入了新的节点后调整所致
         //(若p之前是黑色的话就没必要进行调整了)
         //[解决办法]:将p改成黑色,g变成红色,(导致g的右子树中少了一个黑色节点)
         //此时需要以g为轴进行右旋 g和g的右子树移动脱离原树
         //将p的右子树接到g的左子树上,在将g所在的树整个移动到p的右子树位置
         // 



         //【情况三】:cur、p为红色&cur 为p的右子树,g和u都为黑色
         //【解决办法】:想办法将其变成情况二,以p为轴进行左单旋
         //将cur提高成p的双亲节点,让p变成cur的子树,使cur左子树为p的右子树
         //将指向cur和p的指针交换下位置
         //然后在使用情况二进行处理
         Node *grandFather =pParent->_pParent;
         //情况一:叔叔存在且为红
         if(pParent==grandFather->_pLeft){
           Node *uncle=grandFather->_pRight;
           if(uncle && uncle->_color==RED){
             pParent->_color=BLACK;
             uncle->_color=BLACK;
             grandFather->_color=RED;
             pCur=grandFather;
             pParent=pCur->_pParent;
           }else{
             //叔叔节点不存在或者为黑-->情况二或者情况三
             if(pCur==pParent->_pRight){
               //情况三-->将情况三装换成情况二
               RotateLeft(pParent);
               swap(pParent,pCur);
             }
             //处理情况二
             grandFather->_color=RED;
             pParent->_color=BLACK;
             RotateRight(grandFather);
           }
         }else{
           //叔叔节点在祖父节点的左侧 
           Node* uncle=grandFather->_pLeft;
           if(uncle&&RED=uncle->_color){
             //叔叔存在且为红的情况

           }
         }
     }
   }
   pRoot->_color=BLACK;//保证根节点的颜色为黑色
   //更新红黑树的最大最小节点的指向情况
   _pHead->_pLeft=LeftMost(); 
   _pHead->_pRight=RightMost();
   return true;//插入成功
  }

  Node* LeftMost(){
    Node* pRoot=GetRoot();
    if(nullptr==pRoot){
        return _pHead;
    }
    Node* pCur=pRoot;
    while(pCur->_pLeft){
      pCur=pCur->_pLeft;
      //往左查找最左面的节点
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
      //查找最右侧的节点
    }
    return pCur;
  }

  void RotateLeft(Node* pParent){
    //左单

  }

  void RotateRight(Node* pParent){
    //右单旋
    Node *pSubL=pParent->_pLeft;
    Node *pSubLR=pSubL->_pRight;
    pParent->_pLeft=pSubLR;
    if(pSubLR){
      pSubLR->_pParent=pParent;
    }
    pSubL->_pRight=pParent; 

    //原先的pParent可能还有双亲节点,所以需要将其
    //双亲节点保存一下
    Node* pPParent=pParent->_pParent;
    pParent->_pParent=pSubL;
    pSubL->_pParent=pPParent;
    //pPParent 是根节点的时候
    if(pPParent==_pHead){
      GetRoot()=pSubL;
    }else{
      if(pPParent->_pLeft==pParent)
        pPParent->_pLeft=pSubL;
      else 
        pPParent->_pRight=pSubL;
    }
  }

private:
  Node* _pHead;
  Node* &GetRoot(){
    return _pHead->_pParent;
  }
};
