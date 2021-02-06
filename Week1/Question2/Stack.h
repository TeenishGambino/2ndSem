/*
CH-231-A
a1_p2.h
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>

template<class T, int intialsize = 10>
class Stack
{
    T * pointer; //Points to the start of the element.//
    int size; //number of elements//
    int last_free_position;
    void extend();
    public:
        Stack();
        Stack(const Stack& );
        Stack(int size);
        bool push(T element);
        bool pop (T& out);
        T back(void);
        int getNumEntries();
        ~Stack();

};