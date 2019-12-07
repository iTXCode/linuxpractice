#include<iostream>


template <class T>
struct Node{
    Node(const T val){
        _prev=_next=NULL;
        _value=val;
    }
    Node* _prev;
    Node* _next;
    T _value;
};

template<class T>

class Stack{
public:
 Stack(){
     top=NULL;
     size=0;
 }
    //往栈中插入元素
    void StackPush(Stack<T>* stack,const T val){
        if(stack->top==NULL){
            //如果为第一次插入,则需要将指向栈中节点的指针指向
            //该栈的首结点
            stack->top=new Node<T>(val);
            stack->size++;
            return;
        }
        //针对栈中已经有元素的情况
        Node<T>* cur=new Node<T> (val);
        cur->_prev=stack->top;
        stack->top->_next=cur;
        stack->top=cur;
        stack->size++;
        return;
    }
    
    void StackPop(Stack<T>* stack){
        if( stack==NULL){
            return;
        }
        //若用单链表来实现栈的话,当释放栈顶元素的时候
        //就不能将栈顶指针指向栈的顶部
        //所以我们采用双链表实现栈

        Node<T>* cur=stack->top->_prev;
        delete stack->top;
        stack->top=cur;
        cur->_next=NULL;
        stack->size--;
    }

    //返回栈顶元素
    Node<T>* Top(){
        return this.top;
    }

    //返回栈中元素个数

    int Size(){
       return (int)size; 
    }

    //判断栈是否为空
    bool Empty(){
        if(size==0){
            return true;
        }
        return false;
    }

    //打印栈中的元素
    //按照从栈顶到栈底的顺序依次打印栈中元素
    void StackPrint(const Stack<T>* stack){
        if(stack==NULL){
            return;
        }
         Node<T>* cur=stack->top;
        for(int i=stack->size;i>0;i--){
            if(cur==NULL){
                break;
            }
            printf("%d ",cur->_value);
            cur=cur->_prev;
        }
        std::cout<<std::endl;
    }


private:
    Node<T>* top;//指向栈顶的首元素
    int size;//记录栈的规模
};




