#include "Node.h"
#include<iostream>

using namespace std;

void RBTree::rotateLeft(Node *& x){
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

void RBTree::rotateRight(Node *& x){
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
    Node * y = nullptr;
    Node * x = root;
    Node z(data);

    while(x!=nullptr){
        y = x;
        if (z.data < x->data){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    z.parent = y;

    if(y == nullptr){
        root = &z;
    }else if(z.data < y->data){
        y->left = &z;
    }else{
        y->right = &z;
    }
    z.left = nullptr;
    z.right = nullptr;
    z.setColor(RED);
    RBFixup(&z);
}

void RBTree::RBFixup(Node * z){
    Node * y;
    while(z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right; //uncle//
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{
                if(z == z->parent->right){
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z);
            }
         
        }else{
            y = z->parent->parent->left;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{
                if(z == z->parent->left){
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z);
            }
        }
    }
    root->color = BLACK;
}

Node * RBTree::maximum(Node * temp){
    while(temp->right != nullptr){
        temp = temp->right;
    }
    return temp;
}

Node * RBTree::getMaximum(){
    return maximum(root);
}

Node * RBTree::minimum(Node * temp){
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

Node * RBTree::getMinimum(){
    minimum(root);
}

Node * RBTree::successor(const Node *& x){
    //Finds the minimum value from the right side//
    if (x->right != nullptr){
        return minimum(x->right);
    }
    //if right side is null//
    Node * y = x->parent;
    //First condition checks if x is the root//
    //Second condition: go up the tree until the element is 
    //root or until we find that the node is to the left
    //of an ancestor//

    while (y!=nullptr && x==y->right){
        x = y;
        y = y->parent;
    }
    return y; 
}

Node * RBTree::predecessor(const Node *& x){
    //Goes to the right of the left side of z//
    if(x->left != nullptr){
        return maximum(x->left);
    }
    Node * y = x->parent;
    while(y!=nullptr && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

Node * RBTree::doSearch(Node * x, int data){
    while(x!=nullptr && data != x->data){
        if(data<x->data){
            x = x->left;
        }else{
            x = x->right;
        }
        return x;
    }
}

Node * RBTree::search(int data){
    return doSearch(root, data);
}

void RBTree::Transplant(Node * u, Node * v){
    if(u->parent == nullptr){
        root = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    if(v != nullptr){
        v->parent = u->parent;
    }
}

void RBTree::RB_D_Fixup(Node * x){
    Node * w;
    while(x!=nullptr && x->color == BLACK){
        if(x == x->parent->left){
            w = x->parent->right;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            }else{ 
                if(w->right->color == BLACK){
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        }else{
            w = x->parent->left;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if(w->right->color == BLACK && w->left->color == BLACK){
                w->color = RED;
                x = x->parent;
            }else{ 
                if(w->left->color == BLACK){
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RBTree::deleteRB(Node *& z){
    Node * y = z;
    Node * x;
    Color y_og_color  = y->color;
    if(z->left == nullptr){
        x = z->right; 
        Transplant(z, z->right);
    }else if(z->right == nullptr){
        x = z->left;
        Transplant(z, z->left);
    }else{
        y = minimum(z->right);
        y_og_color = y->color;
        x = y->right;
        if(y->parent == z){
            x->parent = y;
        }else{
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if(y_og_color == BLACK){
        RB_D_Fixup(x);
    }

}