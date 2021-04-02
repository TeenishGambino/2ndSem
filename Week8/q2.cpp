/*
CH-231-A
8_p2.cpp
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

template<typename T>
void printer(T[], int );

void countSort(int arr[], int size, int power){
    //int * max = max_element(arr, arr+size);
    //cout<<pow(10,power)<<endl;
    int * C = new int[10];
    int B[size];   
    //out<<arr[0]<<endl;
    for (int i = 0; i < 10; i++){
        C[i] = 0;
    }

    for(int i = 0; i < size; i++){
        int temp = arr[i];
        int value1 = temp / (int)pow(10, power);
        int value2 = value1 % 10;
        C[value2]++;
    }


    for(int i = 1; i < 10; i++){
        C[i] = C[i] + C[i-1];
    }
    
    for (int i = size-1; i >= 0; i--){
        int temp = arr[i];
        int value1 = temp / (int)pow(10, power);
        int value2 = value1 % 10;
        B[C[value2]-1] = arr[i];
        //cout<<B[C[value2]]<<endl;
        //cout<<"a"<<endl;
        //cout<<"lol:"<<B[i]<<endl;
        C[value2]--;
    }

    //printer(B, size);
    
    for(int i = 0; i < size; ++i){
        arr[i] = B[i];
    }
    
    //delete[] C;
    //delete[] B;
}

void radixSort(int * arr, int size){
    int * max = max_element(arr, arr+size);
    int digit = *max > 0 ? (int) log10 ((double) *max) + 1 : 1;
    for(int i = 0; i < digit; ++i){
        countSort(arr, size, i);
    }
}

int main(){
    int arr[] = {329, 457, 657, 839, 436, 720, 355};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Inital: "<<endl;
    printer(arr, size);
   // cout<<"In Radix: "<<endl;
    radixSort(arr, size);
    cout<<"Final: "<<endl;
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