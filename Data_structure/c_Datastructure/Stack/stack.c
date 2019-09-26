
#include<stdio.h>


typedef struct Stack{
  int array[100];
  int top;
}Stack;

//初始化栈
void StackInit(Stack *stack){
  stack->top=0;
}
//压栈(顺序表的尾插)

void StackPush(Stack* stack, int value){
  if(stack->top==100){
    printf("栈已满，无法继续添加!\n");
    return; 
  }
  stack->array[stack->top]=value;
  stack->top++;
}
//出栈（弹出）（顺序表的尾删）
//只弹出栈顶的第一个元素，不获取

void StackPop(Stack *stack){
  stack->top--;
}
//返回栈顶元素

int StackTop(const Stack* stack){
  return stack->array[stack->top];
}
//判断栈是否为空

int  StackEmpty(const Stack* stack){
  return stack->top==0?1:0;
}

void StackPrint(Stack* stack){
  int num=stack->top;
  printf("num=%d\n",num);
  for(;num>=0;num--){
   printf("%d ",stack->array[num]);
  }
  printf("\n");
}

//获取size
int StackSize(const Stack* stack){
  return stack->top;
};


int main(){
  Stack stack;
  StackInit(&stack);
  //切记要进行初始化
  //保证数列的正常访问
  StackPush(&stack,1);
  StackPush(&stack,2);
  StackPush(&stack,3);
  StackPush(&stack,4);
  StackPush(&stack,5);
  StackPop(&stack);
  printf("size of  stack=%d\n",StackSize(&stack));
  printf("Is stack empty?%d\n",StackEmpty(&stack));
  int num=StackTop(&stack);
  printf("stack->array[top]=%d\n",num);
  StackPop(&stack);
  StackPrint(&stack);
  return 0;
}



#if 0
//栈的实现
#include<stdio.h>

typedef struct Stack{
  int array[100];
  int top;
}Stack;

//初始化栈
void StackInit(Stack *stack){
  stack->top = 0;
}
//压栈(顺序表的尾插)

void StackPush(Stack* stack, int value){
  stack->array[stack->top] = value;
  stack->top++;
}
//出栈（弹出）（顺序表的尾删）
//只弹出栈顶的第一个元素，不获取

void StackPop(Stack *stack){
  stack->top--;
}
//返回栈顶元素

int StackTop(const Stack* stack){
  return stack->array[stack->top-1];
}
//判断栈是否为空

int  StackEmpty(const Stack* stack){
  return stack->top == 0 ? 1 : 0;
}

//获取size
int StackSize(const Stack* stack){
  return stack->top;
}


int main(){
  Stack stack;
  StackInit(&stack);
  StackPush(&stack,1);
  StackPush(&stack,2);
  StackPush(&stack,3);
  StackPush(&stack,4);
  int Empty=StackEmpty(&stack);
  int Size=StackSize(&stack);
  int num=StackTop(&stack);
  printf("Empty=%d\n",Empty);
  printf("Size=%d\n",Size);
  printf("num=%d\n",num);
  StackPop(&stack);
  Empty=StackEmpty(&stack);
  num=StackTop(&stack);
  StackPop(&stack);
  num=StackTop(&stack);
  StackPop(&stack);
  num=StackTop(&stack);
  StackPop(&stack);
  Empty=StackEmpty(&stack);
  return 0;
}

#endif
