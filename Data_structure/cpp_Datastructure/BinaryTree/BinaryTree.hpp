#include<iostream>
#include<assert.h>
#include<string>
#include<malloc.h>
#include<queue>

template <class T>

class TreeNode{
public:
  typedef TreeNode<T>* Bitree;
  typedef TreeNode<T> Node;
public:

  TreeNode(const T val=T()){
    _left=NULL;
    _right=NULL;
    _val=val;
  }
  void PreCreate(Bitree* root,const char *str){
    if(*str=='#'){
      *root=NULL;
    }else{
      *root=(Bitree)malloc(sizeof(Node));
      (*root)->_val=*str;
      PreCreate(&(*root)->_left,++str);
      PreCreate(&(*root)->_right,++str);
    } 
  }
    //前序遍历
    void PreOrderTravel(Bitree root){
      if(root==NULL)
        return ;
      printf("%c",root->_val);
      PreOrderTravel(root->_left);
      PreOrderTravel(root->_right);
    }
    //中序遍历
    void InOrderTravel(Bitree root){
      if(root==NULL)
        return;
      InOrderTravel(root->_left);
      std::cout<<root->_val;
      InOrderTravel(root->_right);
    }
    //后序遍历
    void PostOrderTravel(Bitree root){
      if(root==NULL)
        return;
      PostOrderTravel(root->_left);
      PostOrderTravel(root->_right);
      std::cout<<root->_val;
    }

    //层序遍历
    void LevelTravel(Bitree root){
       if(root==NULL)
         return;
       std::queue<T> q;
       q.push(root);
       while(!q.empty){
        Bitree front=q.front();
        std::cout<<front->_val;
        if(front->left!=NULL)
        q.push(front->_left);
        if(front->_right!=NULL)
        q.push(front->_right);
       }
       
    }
private:
  TreeNode<T>* _left;
  TreeNode<T>* _right;
  T _val;
};




