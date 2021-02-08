/*
CH-231-A
a1_p3.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>

template<class T>
class Node
{
    public: 
        T item;
        Node * next;
        Node  * prev;
};

template<class T>
class LinkedList
{
    int number_of_elements;
    Node<T>* front;
    Node<T>* back;
    //Actual is used to prevent segmentation fault
    //when there is only one element in the linked list//
    int actual;

    public:
        LinkedList();
        ~LinkedList();
        void addNodeFront(T n_item);
        void addNodeBack(T n_item);
        //Deleting and returning//
        T deleteNode_front();
        T deleteNode_back();
        //Returning without//
        T front_return();
        T back_return();

        int getNumberofelem();

};

#include"LinkedList.cpp"