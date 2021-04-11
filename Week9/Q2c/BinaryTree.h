/*
CH-231-A
a9_p2.h
Abiral Banjade
abanjade@jacobs-university.de
*/
#include<iostream>

using namespace std;
//Class Prototype//
class Node;
class LinkedList;
class BinaryTree;

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


class BinaryTree{
    private:
    //Insert data to BST//
        void Insert(Node * root, int data){
            //Checks if the root is null//
            if(this->root == NULL){
                Node * newel = new Node(data);
                this->root = newel;
                return;
            }
            //Checks if the data is less than root//
            if(data <= root->data){
                //If root has no left child//
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
        //To print inorder//
        void printer(Node * node){
            if(node == NULL){
                return;
            }
            printer(node->left);
            cout<<node->data<<" ";
            printer(node->right);
        }
    public:
        Node  * root;
        BinaryTree(){
            this->root = NULL;
        }
        //Helper function to insert//
        void ez_insert(int data){
            Insert(this->root, data);
        }
        //Helper function to print//
        void print(){
            printer(this->root);
        }
};

class LinkedList{
    private:
        struct list{
            int data;
            list * next;
        };
        int count;
        list * head;
    public:
    LinkedList(){
        this->head = NULL;
        this->count = 0;
    }
    //Inputs data into the linked list//
    void push (int x){
        struct list * newel = new list;
        newel->data = x;
        newel->next = head;
        head = newel;
    }
    //Prints things in the linked list//
    void print(){
        struct list * cursor;
        cursor = head;
        while(cursor!= NULL){
            cout<<cursor->data<<" ";
            cursor = cursor->next;
        }
        cout<<endl;
    }
    //Counts the number data in the linked list//
    int ccount(){
        struct list * cursor;
        cursor = head;
        while(cursor!= NULL){
            count++;
            cursor = cursor->next;
        }
        return count;
    }
    //Converts Linked List to BST//
    void Convert(BinaryTree &BT, int start, int end){
        if(start>end){
            return;
        }
        //Root is from the middle//
        int mid = (start+end)/2;
        int i = 0;
        struct list * header = head;
        //Inputs data into the middle value//
        while(i < mid && header->next != NULL){
            header = header->next;
            i++;
        }
        //Inserts values to the BST//
        BT.ez_insert(header->data);
        Convert(BT, start,mid-1);
        Convert(BT, mid+1, end);
    }
    //Helper functionn for conversion//
    void ez_convert(BinaryTree &BT){
        int n = ccount();
        Convert(BT, 0, n-1);
    }
};
