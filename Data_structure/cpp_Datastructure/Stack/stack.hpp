#icnlude<iostream>


tempalte <class T>
struct Node{
    Node(const T val){
        _next=NULL;
        _value=val;
    }
    Node* _next;
    T _value;
};

tempalte<class T>

class Stack{
public:
 Stack(){
     top=NULL;
     size=0;
 }
    //网站中插入元素
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
        stack->top->_next=cur;
        stack->top=cur;
        stack->size++;
        return;
    }
    

    //返回栈顶元素
    Node<T>* Top(){
        return top;
    }

    //返回栈中元素个数

    int size(){
       return size; 
    }

    //判断栈是否为空
    bool Empty(){
        if(size==0){
            return 1;
        }
        return 0;
    }

private:
    Node<T>* top;//指向栈顶的首元素
    int size;//记录栈的规模
}
