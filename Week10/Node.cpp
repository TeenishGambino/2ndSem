#include "Node.h"
#include<iostream>

using namespace std;

void RBTree::rotateLeft(Node * x){
    Node * y = x->right;
    x->right = y->left;
    if(y->left != nullptr){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nullptr){
        root = y;
    }else if(x == x->parent->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
        y->left = x;
        x->parent = y;
    }
}

void RBTree::rotateRight(Node * x){
    Node * y = x->left;
    x->left = y->right;
    if(y->right != nullptr){
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nullptr){
        root = y;
    }else if(x == x->parent->right){
        x->parent->right = y;
    }else{
        x->parent->left = y;
        y->right = x;
        x->parent = y;
    }
}

RBTree::RBTree(){
    this->root = nullptr;
}

void RBTree::insertRB(int data){
    
}