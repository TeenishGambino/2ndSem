/*
CH-231-A
a11_p1.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Node{
    public:
        int key;
        int value;
        Node(int key, int value){
            this->key = key;
            this->value = value;
        }
};

class HashTable{
    private:
    //It is an array that stores pointers//
        Node **arr;
        int maxSize;
        int currentSize;
    public:
        HashTable(){
            maxSize = 100; //change it//
            currentSize = 0;
            arr = new Node *[maxSize];
            for(int i = 0; i < maxSize; i++){
                arr[i] = NULL;
            }
        }
        void hashCode(int key);
        void insertNode(int key, int value);
        int get(int key);
        bool isEmpty(){
            if(currentSize == maxSize){
                return true;
            }else{
                return false;
            }
        }

};

int main(){

    return 0;
}