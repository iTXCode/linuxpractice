#include"BinaryTree.hpp"

void Bitree::PreCreate(Bitree root){
  char val;
  scanf("%c",&val);
  if(val=='#'){
    root._root=NULL; 
  }
  else{
    root._root->_val=val;
    PreCreate(root._root->_left);
    PreCreate(root._root->_right);
  }
}
