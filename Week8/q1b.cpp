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

void bucketSort(float arr[], int size){

    vector<float> b[size];

    for(int i =0; i < size; i++){
        int bi = floor(size * arr[i]);
        b[bi].push_back(arr[i]);
    }

    for(int i = 0; i < size; i++){
        sort(b[i].begin(), b[i].end());
    }

    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < (int)b[i].size(); j++)
            arr[index++] = b[i][j];

}

int main(void){
    float arr[] = {0.9,0.1,0.6,0.7,0.6,0.3,0.1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before"<<endl;
    printer(arr, size);
    bucketSort(arr, size);
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
