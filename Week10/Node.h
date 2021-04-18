#include<iostream>
using namespace std;
enum Color {RED, BLACK};
struct Node{
    int data;
    Color color;
    Node * left, *right, *parent;
};

class RBTree{
    private:
        Node * root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        Node * maximum(Node *);
        Node * minimum(Node *);
        Node * doSearch(Node *, int);
        void Transplant(Node *, Node *);
        void RBFixup(Node *&);
        void RB_D_Fixup(Node *);
        void Printer(Node *);
        Node * BSTinsert(Node *& , Node *&);
        bool isRed(Node *);

    public:
        RBTree();
        void insertRB(int);
        void deleteRB(Node *&);
        Node * predecessor(const Node *&);
        Node * successor(const Node *&);
        Node * getMinimum();
        Node * getMaximum();
        Node * search(int);
        void print();
}; 

