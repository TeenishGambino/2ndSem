/*
CH-231-A
a1_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

//#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
    this->size = 10;
    pointer = new T[size];
    last_non_free_position = -1;
}

template<class T>
Stack<T>::~Stack()
{
    delete[] pointer;
}

template<class T>
Stack<T>::Stack(const Stack &obj)
{
    size = obj.size;
    last_non_free_position = obj.last_non_free_position;

    //deep copy//
    pointer = new T[size];
    for (int i = 0; i < size; i++)
    {
        pointer[i] = obj.pointer[i];
    }
}

template<class T>
Stack<T>::Stack(int size)
{
    this->size = size;
    pointer = new T[this->size];
    last_non_free_position = -1;
}

template<class T>
bool Stack<T>::push (T element)
{
    //Making sure that the stack does not overflow//
    if (last_non_free_position+1 == size)
    {
        return false;	
    }
	last_non_free_position++;				// and insert the element 
	pointer[last_non_free_position] = element;
    return true;
}

template<class T>
bool Stack<T>::pop(T& out)
{
    //Making sure that the stack is not empty//
    if (last_non_free_position == -1)
    {
        return false;
    }

    out = pointer[last_non_free_position];
    last_non_free_position--;

    return true;
}

template<class T>
T Stack<T>::back(void)
{
    return pointer[last_non_free_position];
}

template<class T>
int Stack<T>::getNumEntries()
{
    return last_non_free_position+1;
}
