#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<queue>

typedef char  TNType;

typedef struct TreeNode{
  TNType  _value;
  struct TreeNode* _left;
  struct TreeNode* _right;
}TreeNode,*Bitree;



//按照先序遍历的方式建立二叉树
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


//求二叉树的高度/深度
int TreeDepth(Bitree root){
  if(root==NULL){
    return 0;
  }
  int left=TreeDepth(root->_left);
  int right=TreeDepth(root->_right);
  return (left>right?left:right)+1;
}

//求第K层的结点个数

int KNode(Bitree root,int k){
  if(root==NULL){
    return 0;
  }
  if(k==1)
    return 1;
  return KNode(root->_left,k-1)+KNode(root->_right,k-1);
}


//在二叉树结点中查找某个值
//算法思路:
//1.先确定根结点是否存在
//2.若根存在的话再确定根的值是否和所要的值是否相等
//3.若相等的话再去根节点的左子树中查找指定的值
//4.再到右子树中查找指定的值
//若上述过程中找到了对应的值就返回对应的结点，
//若没有找到的话就返回空值
TreeNode*  Tree_Value_Find(Bitree root,char value){
  if(root==NULL){
    return NULL;
  }
  //在根结点找到了要找的值
  if(root->_value==value){
    return root;
  }
  //当在根结点没有找到对应的值的时候
  //到该根结点对应的左右子树中去找
  TreeNode* left_result=Tree_Value_Find(root->_left,value);
  if(left_result!=NULL){
    return left_result;
  }
  TreeNode* right_result=Tree_Value_Find(root->_right,value);
  if(right_result!=NULL){
    return right_result;
  }else{
    return NULL;
  }
}


//二叉树的层序遍历

void Levelordertravel(TreeNode* root){
  if(root==NULL){
    return;
  }
  std::queue<TreeNode*> qu;
  //先将二叉树的根结点压入队列中
  qu.push(root);
  while(!qu.empty()){

    //首先取出队列中的队首元素,并将队列的
    //首元素弹出队列
    TreeNode* front=qu.front();
    qu.pop();

    //打印出从队列中取出的结点的值
    printf("%c ",front->_value);

    //接着判断该结点的左右子树的情况
    if(front->_left!=NULL){
      qu.push(front->_left);
    }
    //判断从队列中出列的结点的右子树情况
    if(front->_right!=NULL){
      qu.push(front->_right);
    }
  }
}
