/*
CH-231-A
a9_p1.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
using namespace std;

template <class T>
class Stack{
    private:
        struct StackNode{
            T data;
            StackNode * next;
        };
        
        int size;
        int current_size;
    public:
        void push(T x);
        T pop();
        bool isEmpty();
        Stack(int new_size);
        Stack();
        void setSize(int);
        StackNode * top;
}; 
template<class T>
Stack<T>::Stack(){
    this->size = -1;
    this->current_size = 0;
    this->top = NULL;
}
template<class T>
Stack<T>::Stack(int new_size){
    this->size = new_size;
    this->current_size = 0;
    this->top = NULL;
}


template<class T>
bool Stack<T>::isEmpty(){
    if (current_size == 0)
        return true;
    else
        return false;

}

template<class T>
T Stack<T>::pop(){
    if(current_size == 0){
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }


    T odata = top->data;
    StackNode * cursor = top;
    if(current_size == 1){
        top = NULL;
    }else{
        top = top->next;
    }
    
    delete cursor;
    
    current_size--;

    return odata;
}

template<class T>
void Stack<T>::push(T x){
    if(current_size == size){
        cout<<"Stack overflow"<<endl;
        return;
    }
    
    StackNode * newelem = new StackNode;
    newelem->data = x;

    if(top == NULL){
        this->top = newelem;
        newelem->next = NULL;
    }else{
        newelem->next = top;
        top = newelem;
    }
    
    current_size++;
}

template<class T>
void Stack<T>::setSize(int size){
    this->size = size;
}


template<class T>
class Queue{
    private:
        Stack<T> one;
        Stack<T> two;
        int size;
        int current_size;
    public:
        Queue();
        Queue(int size);
        void enqueue(T x);
        T dequeue();
        bool isEmpty();
};

template<class T>
Queue<T>::Queue(){
    this->size = -1;
    this->current_size = 0;
}

template<class T>
Queue<T>::Queue(int size){
    this->size = size;
    this->current_size = 0;
    one.setSize(this->size);
    two.setSize(this->size);
}

template<class T>
void Queue<T>::enqueue(T x){
    if(current_size == size){
        cout<<"Queue Overflow"<<endl;
        exit(0);
    }
    while(!one.isEmpty()){
        two.push(one.top->data);
        one.pop();
    }

    one.push(x);

    while(!two.isEmpty()){
        one.push(two.top->data);
        two.pop();
    }
    current_size++;
}

template<class T>
T Queue<T>::dequeue(){
    if(current_size == 0){
        cout<<"Queue is empty"<<endl;
        exit(0);
    }
    T data = one.top->data;
    one.pop();
    current_size--;
    return data;
}

int main(void){
    Queue<int> Q(5);
    for(int i =0; i < 5; i++){
        Q.enqueue(i);
    }
    for(int i = 0; i < 5; i++){
        cout<<Q.dequeue()<<endl;
    }
    return 0;
}