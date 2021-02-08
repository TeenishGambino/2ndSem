/*
CH-231-A
a1_p4.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>

using namespace std;

template<class T>
LinkedList<T>::LinkedList()
{
   number_of_elements = 0;
   actual = 0;
   front = NULL;
   back = NULL;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *pointer;
    while(front != back)
    {
        pointer = back;
        back->next = NULL;
        back = pointer->prev;
        delete pointer;
    }
    pointer = front;
    front->next = front->prev = NULL;
    back->next = back->prev = NULL;
    delete pointer;
}

template<class T>
int LinkedList<T>::getNumberofelem()
{
    return number_of_elements;
}

template<class T>
void  LinkedList<T>::addNodeFront(T n_item)
{
    Node<T> * newelem = new Node<T>;
    newelem->item = n_item;
    newelem->next = NULL;
    newelem->prev = NULL;

    if (actual == 1)
    {
        
        actual = 0;
        Node<T> * temp = front;
        front = newelem;
        back = newelem;
        front->next = front->prev = NULL;
        back->next = back->prev = NULL;
        number_of_elements = 1;
        delete temp;

    }
    else if(number_of_elements == 0)
    {
        front = newelem;
        back = newelem;
        front->next = front->prev = NULL;
        back->next = back->prev = NULL;
        number_of_elements = 1;
    }
    else
    {
        front->prev = newelem;
        newelem->next = front;
        front = newelem;
        number_of_elements++;
        front->prev = NULL;
    }
}

template<class T>
void  LinkedList<T>::addNodeBack(T n_item)
{
    Node<T> * newelem = new Node<T>;
    newelem->item = n_item;
    newelem->next = NULL;
    newelem->prev = back;

    if (actual == 1)
    {
        
        actual = 0;
        Node<T> * temp = back;
        front = newelem;
        back = newelem;
        front->next = front->prev = NULL;
        back->next = back->prev = NULL;
        number_of_elements = 1;
        delete temp;

    }
    
    else if(number_of_elements == 0)
    {
        front = newelem;
        back = newelem;
        number_of_elements = 1;
    }
    else
    {
        back->next = newelem;
        back = newelem;
        number_of_elements++;
    }
}

template<class T>
T LinkedList<T>::deleteNode_back()
{
    T out;
    if (number_of_elements == 0)
    {
        cout<<"Sorry no elements in the linked list"<<endl;
        return -1;
    }
    else if(number_of_elements == 1)
    {
        T temp = back_return();
        actual = 1;
        number_of_elements--;
        return temp;
    }
    else
    {
        Node<T> *temp = back;
        back = temp->prev;
        out = temp->item;
        delete temp;
        back->next = NULL;
        number_of_elements--;
        return out;
    }
    
}

template<class T>
T LinkedList<T>::deleteNode_front()
{
    Node<T>* temp; 
    T out;
    if (number_of_elements == 0)
    {
        cout<<"Sorry no elements in the linked list"<<endl;
        return -1;
    }
    else if(number_of_elements == 1)
    {
        T temp = front_return();
        actual = 1;
        number_of_elements--;
        return temp;
    }
    else
    {
        temp = front;
        front= front->next;
        front->prev = NULL;
        out = temp->item;
        delete temp;
        number_of_elements--;
    }
    return out;
}

template<class T>
T LinkedList<T>::front_return()
{
    //Needed if no elements are in the list//
    if (number_of_elements == 0)
    {
        cout<<"Sorry no elements in the linked list"<<endl;
        return -1;
    }
    return front->item;
}

template<class T>
T LinkedList<T>::back_return()
{
    if (number_of_elements == 0)
    {
        cout<<"Sorry no elements in the linked list"<<endl;
        return -1;
    }
    return back->item;
}