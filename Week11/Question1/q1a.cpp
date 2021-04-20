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



class Hash{
    private:
        int * hashTable;
        int curr_size;
        int act_size;

        int hash_one(int value){
            return(value%5);
        }

        int hash_two(int value){
            return ((7*value) % 8);
        }

    public:
        Hash(int size){
            hashTable = new int[size];
            curr_size = 0;
            act_size = size;
            for(int i = 0; i < size; i++){
                hashTable[i] = -1;
                
            }
        }


        void insertItem(int x){
            if(curr_size == act_size){
                return;
            }
            
            int index = hash_one(x);
            if(hashTable[index] != -1){
                int index2 = hash_two(x);
                int i = 1;
                while(1){
                    int n_index = (index*i + index2)%(act_size+1);
                    if(hashTable[n_index] == -1){
                        hashTable[n_index] = x;
                        break;
                    }
                    i++;
                }
            }else{
                hashTable[index] = x;
            }
            curr_size++;
        }

        void print(){
            for(int i = 0; i < act_size; i++){
                cout<<hashTable[i]<<" ";
            }
            cout<<endl;
        }
};   


int main(){
    int seq[] = {3,10,2,4};
    int size = sizeof(seq)/sizeof(seq[0]);

    Hash h(size);
    for(int i = 0; i < size; i++){
        h.insertItem(seq[i]);
    }

    h.print();
    return 0;
}