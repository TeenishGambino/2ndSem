/*
CH-231-A
a9_p2b.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include"BinaryTree.h"
#include<iostream>

using namespace std;

int main(void){
    LinkedList L;
    for(int i = 9; i >= 1; i--){
        L.push(i);
    }
    //L.print();
    BinaryTree BT;
    L.ez_convert(BT);
    //Prints inorder//
    BT.print();
    cout<<endl;
    return 0;
}