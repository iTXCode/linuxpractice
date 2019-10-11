#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef char  TNType;

typedef struct TreeNode{
  TNType  _value;
  struct TreeNode* _left;
  struct TreeNode* _right;
}TreeNode,*Bitree;

void CreateTree(Bitree* root){
  TNType node;
  scanf("%c",&node);
  if(node=='#'){
    *root=NULL;  //叶子结点的产生
  }else{
    *root=(Bitree)malloc(sizeof(TreeNode));
    (*root)->_value=node;
    CreateTree(&(*root)->_left);
    CreateTree(&(*root)->_right);
  }

}


//先序遍历
void PreOrderTravel(Bitree root){
  if(root!=NULL){
    printf("%c ",root->_value);
    PreOrderTravel(root->_left);
    PreOrderTravel(root->_right);
  }
}

//中序遍历
void InOrderTravel(Bitree root){
  if(root!=NULL){
    InOrderTravel(root->_left);
    printf("%c ",root->_value);
    InOrderTravel(root->_right);
  }
}

//后续遍历
void PostOrderTravel(Bitree root){
  if(root!=NULL){
    PostOrderTravel(root->_left);
    PostOrderTravel(root->_right);
    printf("%c ",root->_value);
  }
}

//输出树中的叶子结点
void  PreOrder(Bitree root){
  if(root!=NULL){
    if(root->_left==NULL&&root->_right==NULL)
      printf("%c ",root->_value);
    PreOrder(root->_left);
    PreOrder(root->_right);
    //按先序遍历的方式输出所有遇到的叶子节点
  }
}

int Leafcout=0;
//定义一个全局变量用于统计递归过程中的二叉树叶子个数


int PostOrder(Bitree root){
  if(root!=NULL){
    PostOrder(root->_left);
    PostOrder(root->_right);
    if(root->_left==NULL&&root->_right==NULL)
      Leafcout++;
  }
  return Leafcout;
}


//采用分治算法
int Leaf(Bitree root){
  int leaf=0;
  if(root==NULL){
    leaf=0;
  }
  else if((root->_left==NULL)&&(root->_right==NULL)){
    leaf=1;
  }else{
    leaf=Leaf(root->_left)+Leaf(root->_right);
  }
  return leaf;
}

