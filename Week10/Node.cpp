#include "Node.h"
#include<iostream>

using namespace std;

void RBTree::rotateLeft(Node *& x){
    Node * y = x->right;
    x->right = y->left;
    if(y->right != NULL){
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL){
        root = y;
    }else if(x == x->parent->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
        y->left = x;
        x->parent = y;
}

void RBTree::rotateRight(Node *& x){
    Node * y = x->left;
    x->left = y->right;
    if(y->left != NULL){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL){
        root = y;
    }else if(x == x->parent->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

RBTree::RBTree(){
    this->root = NULL;
}

Node * RBTree::BSTinsert(Node *& root, Node *& pt){
    if(root == NULL){
        return pt;
    }
    if(pt->data < root->data){
        root->left = BSTinsert(root->left, pt);
        root->left->parent = root;
    }else if(pt->data > root->data){
        
        root->right = BSTinsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

void RBTree::insertRB(int data){
    Node * z = new Node;
    
    z->data = data;
    z->color = RED;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;

    if(root == NULL){
        root = z;
    }else{
        BSTinsert(root, z);
    }
    RBFixup(z);
    
}

void RBTree::RBFixup(Node *&z)
{
    while (z->parent != NULL && z->parent->color == RED){
        if (z->parent == z->parent->parent->left){
            Node *uncle = z->parent->parent->right;
            Node *grandparent = z->parent->parent;
            if (uncle != NULL && uncle->color == RED){
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{
                if (z == z->parent->right){
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(grandparent);
                }
        }else{
            Node *grandparent = z->parent->parent;
            Node *uncle = z->parent->parent->left;
            if (uncle != NULL && uncle->color == RED){
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{
                if (z == z->parent->left){
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(grandparent);
                }
            }
        }
    root->color = BLACK;
}

Node * RBTree::maximum(Node * temp){
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node * RBTree::getMaximum(){
    return maximum(root);
}

Node * RBTree::minimum(Node * temp){
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node * RBTree::getMinimum(){
    return minimum(root);
}

Node * RBTree::successor(const Node *& x){
    //Finds the minimum value from the right side//
    if (x->right != NULL){
        return minimum(x->right);
    }
    //if right side is null//
    Node * y = x->parent;
    //First condition checks if x is the root//
    //Second condition: go up the tree until the element is 
    //root or until we find that the node is to the left
    //of an ancestor//

    while (y!=NULL && x==y->right){
        x = y;
        y = y->parent;
    }
    return y; 
}

Node * RBTree::predecessor(const Node *& x){
    //Goes to the right of the left side of z//
    if(x->left != NULL){
        return maximum(x->left);
    }
    Node * y = x->parent;
    while(y!=NULL && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

Node * RBTree::doSearch(Node * x, int data){
    
    while(x!=NULL && data != x->data){
        if(data < x->data){
            x = x->left;
        }else{
            x = x->right;
        }  
    }
    return x;
}

Node * RBTree::search(int data){
    if(doSearch(root, data) == NULL){
        return NULL;
    }else{
        return doSearch(root, data);
    }
    
}

void RBTree::Transplant(Node * u, Node * v){
    if(u->parent == NULL){
        root = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    if(v != NULL){
        v->parent = u->parent;
    }
}

void RBTree::RB_D_Fixup(Node * x){
    Node * w;
    while(x!=NULL && x->color == BLACK){
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
    
    if(z->left == NULL){
        x = z->right; 
        Transplant(z, z->right);
    }else if(z->right == NULL){
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

void RBTree::Printer(Node * x){
    cout<<x->data<<":";
    cout<<x->color<<" ";

    if(x->left != NULL){
        Printer(x->left);
    }
    if(x->right != NULL){
        Printer(x->right);
    }
}

void RBTree::print(){
    Printer(root);
    cout<<endl;
}