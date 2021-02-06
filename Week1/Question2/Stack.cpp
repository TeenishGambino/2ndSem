/*
CH-231-A
a1_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include "Stack.h"

template<class T, int initalsize>
Stack<T,initalsize>::Stack()
{
    pointer = new T[initalsize];
    size = initalsize;
    last_free_position = -1;
}

template<class T, int intialsize>
Stack<T, intialsize>::~Stack()
{
    delete[] pointer;
}

template<class T, int intialsize>
Stack<T, intialsize>::Stack(const &obj)
{
    size = obj.size;
    last_free_position = obj.last_free_position;

    //deep copy//
    pointer = new T[size];
    for (int i = 0; i < size; i++)
    {
        pointer[i] = obj.pointer[i];
    }
}

template<class T, int intialsize>
Stack<T, intialsize>::Stack(int size)
{
    this->size = size;
    pointer = new T[this->size];
    last_free_position = -1;
}

template<class T, int initialsize>
Stack<T, initialsize>::~Stack()
{
	delete[] pointer;
} 

template<class T, int initialsize>
bool Stack<T, initialsize>::push (T element)
{
    if (last_free_position; + 1 == size)
    {
        extend();	
    }
	last_free_position++;				// and insert the element 
	pointer[last_free_position] = element;
}