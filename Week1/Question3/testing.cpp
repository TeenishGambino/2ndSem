/*
CH-231-A
testa1_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include"LinkedList.h"
#include<iostream>

using namespace std;

int main(void)
{
    LinkedList<int> test;
    //Testing if the deletes Function properly//
    cout<<"Test 1: "<<endl<<endl;
    test.deleteNode_front();
    test.deleteNode_back();
    cout<<endl;

    cout<<"Test 2: "<<endl<<endl;

    //Checking addNode back//
    test.addNodeBack(3);
    //test.addNodeFront(2);

    //Checking if front return and back return work//
    cout<<"Front Return: "<<test.front_return()<<endl;
    cout<<"Back Return: "<<test.back_return()<<endl;
    cout<<"Number of items in this test: "<<test.getNumberofelem()<<endl;

    cout<<endl<<"Test 3: "<<endl<<endl;
    //Deleting to see if it works//
    //int a = test.deleteNode_back();
    cout<<"Deleted Value: "<<test.deleteNode_back()<<endl;
    cout<<"Now the number of items: "<<test.getNumberofelem()<<endl;
    test.addNodeFront(70);
    cout<<"Newly added value is: "<<test.front_return()<<endl;
    
    cout<<endl<<"Test back function"<<endl;
    //Now to test deleteNode_front()//
    cout<<"Deleted Value: "<<test.deleteNode_front()<<endl;
    cout<<"Now the number of items: "<<test.getNumberofelem()<<endl;
    test.addNodeFront(100);
    cout<<"Newly added value is: "<<test.back_return()<<endl;

    cout<<"Deleted Value: "<<test.deleteNode_back()<<endl;

    //Checking for multiple values//
    cout<<endl<<"Test 4: "<<endl;
    
    test.addNodeFront(123);
    test.addNodeFront(4);
    test.addNodeBack(6);
    test.addNodeFront(0);
    test.addNodeFront(42);
    test.addNodeBack(9);

    cout<<"Number of elements: "<<test.getNumberofelem()<<endl;
    cout<<"Front value: "<<test.front_return()<<endl;
    cout<<"Back value: "<<test.back_return()<<endl;

    cout<<"Deleted value: "<<test.deleteNode_front()<<endl<<endl;
    cout<<"Number of elements: "<<test.getNumberofelem()<<endl;

    cout<<"Front Value: "<<test.front_return()<<endl;
    cout<<"Deleted value: "<<test.deleteNode_back()<<endl;

    cout<<"Number of elements: "<<test.getNumberofelem()<<endl<<endl;
    
    cout<<"Back Value: "<<test.back_return()<<endl;
    cout<<"Deleted value: "<<test.deleteNode_back()<<endl;
    cout<<"Number of elements: "<<test.getNumberofelem()<<endl;



    return 0;
}