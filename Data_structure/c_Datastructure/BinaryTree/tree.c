#include"BinaryTree.h"


void menu(){
  printf("\n");
  printf("********************\n");
  printf("***   0：退出    ***\n");
  printf("***  1:先序遍历  ***\n");
  printf("***  2:中序遍历  ***\n");
  printf("***  3: 后序遍历 ***\n");
  printf("********************\n");
}

void TestTree(){ 
   int num=1;
   Bitree tree;                
   CreateTree(&tree);          
 
   do{
     menu();
     scanf("%d",&num);
     switch(num){
       case 1:
         PreOrderTravel(tree);  
         break;
       case 2:
         InOrderTravel(tree);    
         break;
       case 3:
         PostOrderTravel(tree);
         break;
       case 0:
         printf("退出程序\n");
         break;
       default:
         printf("输入错误,请重新输入!\n");
         break;
     }

   }while(num);
   PreOrder(tree);
}                             
              
int main(){
  TestTree();
  return 0;
}
