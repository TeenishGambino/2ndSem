/*
CH-231-A
8_p1b.cpp
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

void countSort(string arr[], int size, int pos){
    int max = 129; //Ascii 128, and we need to store the 128, hence 128+1//
    string temp[size];
    int C[max];
    for (int i = 0; i < max; i++){
        C[i] = 0;
    }

    for(int i = 0; i < size; i++){
        if(pos < (int)arr[i].size())
            C[arr[i][pos]+1]++;
        else
            C[0]++;
    }

    for(int i = 1; i < max; i++){
        C[i] = C[i] + C[i-1];
    }

    for (int i = size-1; i >= 0; i--){
        //Condition needed to weed out words smaller,
        //then the current psoition we are looking at.
        if((int)arr[i].size()>pos){
            temp[C[arr[i][pos]+1]-1] = arr[i];
            C[arr[i][pos]+1]--; 
        }else{
            temp[C[0]-1] = arr[i];
            C[0]--;
        }
    }
    for(int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
}

void radixSort(string arr[], int size){
    int max_length = 0;
    for(int i =0; i < size; ++i){
        if((int)arr[i].size() > max_length){
            max_length = arr[i].size();
        }
    }
    //cout<<max_length<<endl;
    for(int i = max_length-1; i >=0; i--){
        
        countSort(arr,size, i);
    }
}

int main(void){
    string arr[] = {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before:"<<endl;
    printer(arr, size);
    radixSort(arr, size);
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

