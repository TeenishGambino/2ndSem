/*
CH-231-A
a7_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<vector>
#include <fstream>
#include <chrono>
#include<cmath>

using namespace std;
using namespace chrono;

/*Utility function*/
//Used for swapping values//
void exchange(int &a, int &b);
//Prints array//
void printer(int[], int );

void quickSort(int arr[], int p, int p2, int r){
    int x = arr[p];
    int y = arr[p2];
    int i = p;
    int j = p2;
}
int partition(int arr[], int p, int p2, int r){
    int x = arr[p];
    int y = arr[p2];
    int i = p;
    int j = p2;

    for(int z = p2+1; z<r;++z){
        if(arr[j] <= x || arr[j] <= y){
            
        }
    }
}

int main(void){

    return 0;
}










void exchange(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void printer(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}