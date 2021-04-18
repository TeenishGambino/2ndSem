/*
CH-231-A
a10_p2b.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include"Node.h"

using namespace std;

int main(){
    RBTree tree;
    
    tree.insertRB(10);
    tree.print();
    tree.insertRB(420);
    tree.print();
    tree.insertRB(39);
    tree.print();
    tree.insertRB(4);
    tree.insertRB(26);
    tree.insertRB(14);
    
    cout<<endl;
    cout<<"Tree Insertion complete"<<endl;
    tree.print();
    cout<<endl;
    Node *node = tree.search(14);
    cout<<"After deletion"<<endl;
    tree.deleteRB(node);
    tree.print();

    return 0;
}