/*
CH-231-A
a9_p2.h
Abiral Banjade
abanjade@jacobs-university.de
*/
#include<iostream>

using namespace std;

//Node for the BST//
class Node{
    public:
        int data;
        Node * right;
        Node * left;

        Node(int data){
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
};

class LinkedList{
    private:
        struct list{
            int data;
            list * next;
        };

        list * head;
    public:
    LinkedList(){
        this->head = NULL;
    }
    //Input data to Linked List//
    void push (int x){
        struct list * newel = new list;
        newel->data = x;
        newel->next = head;
        head = newel;
    }
    //Print the Linked List//
    void print(){
        struct list * cursor;
        cursor = head;
        while(cursor!= NULL){
            cout<<cursor->data<<" ";
            cursor = cursor->next;
        }
        cout<<endl;
    }
};

class BinaryTree{
    private:
    //Insert data to BST//
        Node  * root;
        void Insert(Node * root, int data){
            //Checks if the root is null//
            if(this->root == NULL){
                Node * newel = new Node(data);
                this->root = newel;
                return;
            }
            //Checks if the data is less than root//
            if(data <= root->data){
                if(root->left == NULL){
                    Node * newel = new Node(data);
                    root->left = newel;
                }
                //If root does have a left child//
                //We go left until we find its position//
                else{
                    Insert(root->left, data);
                }
            //if data is right child of root//
            }else{
                if(root->right == NULL){
                    Node * newel = new Node(data);
                    root->right = newel;
                }
                else{
                    Insert(root->right, data);
                }
            }
        }
        void Convert(Node * root, LinkedList &list){
            if(root->left!=NULL){
                Convert(root->left, list);
            }
            list.push(root->data);
            if(root->right != NULL){
                Convert(root->right, list);
            }
        }
    
    public:
        BinaryTree(){
            this->root = NULL;
        }
        
        void ez_insert(int data){
            Insert(this->root, data);
        }

        void ez_convert(LinkedList &list){
            Convert(this->root, list);
        }

};