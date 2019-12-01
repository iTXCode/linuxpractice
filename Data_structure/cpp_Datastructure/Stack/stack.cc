#include"stack.hpp"

void TestStack(){
    Stack<int> stack;
    stack.StackPush(&stack,1);
    stack.StackPush(&stack,2);
    stack.StackPush(&stack,3);
    stack.StackPush(&stack,4);
    stack.StackPrint(&stack);
    stack.StackPop(&stack);
    stack.StackPrint(&stack);
    std::cout<<stack.Empty()<<std::endl;
    std::cout<<stack.Size()<<std::endl;
}

int main(){
    TestStack();
    return 0;
}

