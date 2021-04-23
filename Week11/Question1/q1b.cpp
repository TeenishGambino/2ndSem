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
            maxSize = 500; 
            currentSize = 0;
            arr = new Node *[maxSize];
            for(int i = 0; i < maxSize; i++){
                arr[i] = NULL;
            }
        }
        int hashCode(int key){
                return key % maxSize;
            }
        void insertNode(int key, int value){
            if(currentSize >= maxSize){
                cout<<"Hash table full"<<endl;
                exit(1);
            }

            int index;
            int i = 0;

            while (1)
            {
                index = hashCode(key+i);
                if(index >= maxSize){
                    index = 0;
                }
                if(arr[index] == NULL){
                    Node * newelm = new Node(key, value);
                    arr[index] = newelm;
                    currentSize++;
                    return;
                }else{
                    i++;
                }
            }
        }

        int get(int key){
            if(isEmpty()){
                cout<<"Hash table empty"<<endl;
                return -1;
            }
            int i = 0;
            while(i<maxSize){
                int index = hashCode(key+i);
                if(arr[index]->key == key){
                    return arr[index]->value;
                }else{
                    i++;
                }
            }

            return -1;
        }
        bool isEmpty(){
            if(currentSize == 0){
                return true;
            }else{
                return false;
            }
        }

};

int main(){
    HashTable H;
    for(int i = 0; i < 100; i++){
        H.insertNode((i*i)/2, i);
    }

    for(int i = 0; i < 100; i++){
        cout<<H.get((i*i)/2)<<endl;
    }

    return 0;
}