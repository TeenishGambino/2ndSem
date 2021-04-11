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
    BinaryTree BT;
    BT.ez_insert(5);
    BT.ez_insert(3);
    BT.ez_insert(4);
    BT.ez_insert(2);
    BT.ez_insert(1);
    BT.ez_insert(7);
    BT.ez_insert(6);
    BT.ez_insert(8);
    BT.ez_insert(9);

    LinkedList L;

    BT.ez_convert(L);
    L.print();
    return 0;
}