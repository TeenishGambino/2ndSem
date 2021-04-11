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
        StackNode * top;
        int size;
        int current_size;
    public:
        void push(T x);
        T pop();
        bool isEmpty();
        Stack(int new_size);
        Stack();
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

int main(void){
    Stack<int> S(5);
    for(int i = 0; i < 5; i++){
        S.push(i);
    }
    for(int i = 0; i < 5; i++){
        cout<<S.pop()<<endl;
    }
    return 0;
}