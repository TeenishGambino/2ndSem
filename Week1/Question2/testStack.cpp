/*
CH-231-A
testa1_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include"Stack.h"

using namespace std;

int main(void)
{
    //Used for pop//
    int temp;
    //Testing when things are normal//
    cout<<"Test 1:"<<endl<<endl;
    Stack<int> test1(3);
    cout<<"Pushing values:"<<endl;
    test1.push(420);
    test1.push(6);
    test1.push(9);
    cout<<"Items before pop: "<<test1.getNumEntries()<<endl;
    test1.pop(temp);
    //The popped element//
    cout<<"Items before pop: "<<test1.getNumEntries()<<endl;
    cout<<"Value of the popped item:" << temp<<endl<<endl;

    //Test2:
    //Checks functionality of Stack(), and
    //pop when no elements are present
    //push function testing//
    temp = 0;
    cout<<"Temp 2:"<<endl<<endl;
    Stack<int> test2;
    cout<<"Popping an empty array"<<endl;
    test2.pop(temp);
    //The temp should still be 0, because no elements in the stack yet.//
    cout<<temp<<endl;

    cout<<"Pushing more values than array can hold"<<endl;
    //<11, to check the limits of push function//
    for (int i = 0; i < 11; i++)
    {
        test2.push(i);
    }
    //The number of entries should be 10, even thought 
    //I pushed 11 items//

    cout<<"Entries after trying to push more values: "<<test2.getNumEntries()<<endl;

    cout<<"Temp 3:"<<endl<<endl;
    test2.pop(temp);
    test2.pop(temp);
    //Test 3: 
    //Checking back and copy constructor//
    Stack <int> test3 = test2;
    cout<<"Value using back() : "<<test3.back()<<endl;
    cout<<"Popping more times than needed"<<endl;
    for(int i = 0; i < 10; i++)
    {
        //Popping more times then needed,
        //to make sure pop works//
        test3.pop(temp);
    }
    cout<<"Number of items after popping: "<<test3.getNumEntries()<<endl<<endl;
}