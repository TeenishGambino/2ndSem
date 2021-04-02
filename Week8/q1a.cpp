/*
CH-231-A
8_p1a.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>
#include <chrono>
#include<cmath>

using namespace std;
using namespace chrono;

//Prints array//
template<typename T>
void printer(T[], int );

void countSort(int * arr, int size){
    int * max = max_element(arr, arr+size);
    int * C = new int[*max+1];
    int * B = new int[size];
    //out<<arr[0]<<endl;
    for (int i = 0; i <= *max; ++i){
        C[i] = 0;
    }

    for(int i = 0; i < size; ++i){
        C[arr[i]]++;
    }

    for(int i = 1; i <= *max; ++i){
        C[i] = C[i] + C[i-1];
    }

    for (int i = size-1; i >= 0; i--){
        //cout<<B[0]<<endl;
        B[C[arr[i]]-1] = arr[i];
        //cout<<"lol:"<<B[i]<<endl;
        C[arr[i]]--;
    }

    for(int i = 0; i < size; ++i){
        arr[i] = B[i];
    }

    delete[] C;
    delete[] B;
}

int main(void){
    int arr[] = {9, 1, 6, 7, 6, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before"<<endl;
    printer(arr, size);
    countSort(arr, size);
    cout<<"After"<<endl;
    printer(arr, size);
    return 0;
}
template<typename T>
void printer(T arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

