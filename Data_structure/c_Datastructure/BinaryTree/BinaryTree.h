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

void  PreOrder(Bitree root){
  if(root!=NULL){
    if(root->_left==NULL&&root->_right==NULL)
      printf("%c\n",root->_value);
    PreOrder(root->_left);
    PreOrder(root->_right);
    //按先序遍历的方式输出所有遇到的叶子节点
  }
}


void  PostOrder(Bitree root){
  if(root!=NULL){
    PostOrder(root->_left);
    PostOrder(root->_right);
    if(root->_left==NULL&&root->_right==NULL){
    } 
  }
}
