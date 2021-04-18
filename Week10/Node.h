#include<iostream>
enum Color {RED, BLACK};
class Node{
    public:
        int data;
        Node * left; 
        Node * right;
        Node * parent;
        Color color; //0->black, 1->red//
    Node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
        this->color = RED;
    }
    void setColor(Color color){
        this->color = color;
    }
};

Node Sentinal(0);
//Sentinal.setColor(1);

class RBTree{
    private:
        Node * root;
    protected:
        void rotateLeft(Node *);
        void rotateRight(Node *);
    public:
        RBTree();
        void insertRB(int);
        void deleteRB(int);
        Node * predecessor(const Node *&);
        Node * successor(const Node *&);
        Node * getMinimum();
        Node * getMaximum();
        Node * search(int);
}; 

