#include<iostream>
#include<malloc.h>
#include<queue>

template <class T>
  struct TreeNode{
  TreeNode<T>* _left;
  TreeNode<T>* _right;
  T _val;
};

template <class T>
class  Bitree{
public:
  Bitree(){
    _root=NULL;
  }
  //二叉树的建立
  TreeNode<T>** CreateTree(TreeNode<T>** root){
    T val;
    std::cin>>val;
    if(val=='#'){
      *root=NULL;
    }
    else{
      if(*root==NULL){
        (*root)=(TreeNode<T>*)malloc(sizeof(TreeNode<T>));
        (*root)->_left=(*root)->_right=NULL;
      }
      (*root)->_val=val;
      CreateTree(&(*root)->_left);
      CreateTree(&(*root)->_right);
    }
    return root;
  }

  //将Bitree类中的_root指针指向创建的二叉树
void   BitreeInit(Bitree* root){
    TreeNode<T>** t_root=CreateTree(&(root->_root));
    root->_root=*t_root;
  }
//先序遍历的递归实现
void PreOrderTravel(TreeNode<T>*  root){
  if(root==NULL){
    return;
  }
  std::cout<<root->_val;
  PreOrderTravel(root->_left);
  PreOrderTravel(root->_right);
}

//返回类中的_root指针
TreeNode<T>* getroot(){
  return _root;
}

//中序遍历的递归实现
void InOrderTravel(TreeNode<T>* root){
  if(root==NULL){
    return;
  }
  InOrderTravel(root->_left);
  std::cout<<root->_val;
  InOrderTravel(root->_right);
}

//后序遍历的递归实现
void PostOrderTravel(TreeNode<T> *root){
  if(root==NULL){
    return;
  }
  PostOrderTravel(root->_left);
  PostOrderTravel(root->_right);
  std::cout<<root->_val;
}

//层序遍历
void LevelTravel(TreeNode<T>* root){
  if(root==NULL){
    return;
  }
  std::queue<TreeNode<T>*> q;
  q.push(root);
  while(!q.empty()){
    TreeNode<T>* front=q.front();
    q.pop();
    std::cout<<front->_val;
    if(front->_left!=NULL){
      q.push(front->_left);
    }
    if(front->_right!=NULL){
      q.push(front->_right);
    }
  }
}

//在二叉树中查找结点值与指定值相等的结点
TreeNode<T>* Tree_Value_Find(TreeNode<T>* root,T val=T()){
  if(root==NULL){
    return NULL;
  }
  if(root->_val==val){
    return root;
  }

  //在左子树中查找指定的值
  TreeNode<T> *left=Tree_Value_Find(root->_left,val);
  if(left!=NULL){
    return left;
  }
  //在右子树中查找指定的结点
  return Tree_Value_Find(root->_right,val);
}


//求二叉树的高度
int  Tree_Height(TreeNode<T>* root){
  if(root==NULL){
    return 0;
  }

  int left=Tree_Height(root->_left);
  int right=Tree_Height(root->_right);
  return (left>right?left:right)+1;
}

//打印出二叉树中叶子结点的值

void Tree_Left(TreeNode<T>* root){
  if(root==NULL){
    return ;
  }
  if(root->_left==NULL&root->_right==NULL){
    std::cout<<root->_val;
  }
  Tree_Left(root->_left);
  Tree_Left(root->_right);
}

//计算二叉树中叶子结点的个数
int Left_Num(TreeNode<T>* root){
  if(root==NULL){
    return 0;
  }
  if(root->_left==NULL&&root->_right==NULL)
    return 1;
  //计算二叉树中叶子结点的个数
  int left=Left_Num(root->_left);
  int right=Left_Num(root->_right);
  return left+right;
}


//输出二叉树中第K层结点的值
void  Level_K_Value(TreeNode<T>* root,int k){
  if(root==NULL){
    return;
  }
  if(k==1){
    std::cout<<root->_val;
    return;
  }
  Level_K_Value(root->_left,--k);
  //这里需要注意的是对于同一个根结点的左右子树来说
  //当左子树满足条件时k的值为左子树满足时的值,所以相对
  //于右子树来说--k变成了根结点层次的值,因此需要改成k-- 
  Level_K_Value(root->_right,k--);
}

//统计第k层结点的个数
int K_LevelNum(TreeNode<T>* root,int k){
  if(root==NULL){
    return 0;
  }

  if(k==1){
    return 1;
  }
  return K_LevelNum(root->_left,--k)+K_LevelNum(root->_right,k--);
}
private:
  TreeNode<T>* _root;
};

