/*
CH-231-A
a7_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

/*Made use of Yaroslavskiy(2009), https://codeblab.com/wp-content/uploads/2009/09/DualPivotQuicksort.pdf*/

#include<iostream>
#include<vector>
#include <fstream>
#include <chrono>
#include<cmath>
#define TINY_SIZE 17
#define DIST_SIZE 13

using namespace std;
using namespace chrono;

/*Utility function*/
//Used for swapping values//
void exchange(int &a, int &b);
//Prints array//
void printer(int[], int );
int * array_gen(int size);
int random_number(int size);


void dualPivotQuicksort(int arr[], int left, int right, int div);
void randomdualPivotQuicksort(int arr[], int left, int right, int div);

int main(void){
    int size = 35;
    int * arr = new int[size];
    cout<<"Non Random:"<<endl;
    arr = array_gen(size);
    //int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before: "<<endl;
    printer(arr, size);
    cout<<"After: "<<endl;
    dualPivotQuicksort(arr, 0, size-1, 3);
    //sort(arr, 0, size -1);
    printer(arr, size);
    cout<<"Random:"<<endl;
    arr = array_gen(size);
    //int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before: "<<endl;
    printer(arr, size);
    cout<<"After: "<<endl;
    randomdualPivotQuicksort(arr, 0, size-1, 3);
    //sort(arr, 0, size -1);
    printer(arr, size);
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

int * array_gen(int size)
{
    int *arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = random_number(size);
    }
    return arr;
}

int random_number(int size)
{
    int randomNumber;
    int number;
    randomNumber = rand();
    number = (randomNumber%(size));

    return number;
}


void dualPivotQuicksort(int arr[], int left, int right, int div){
    int len = right - left;
    if (len < 27){
        for(int i = left + 1; i <=right; i++){
            for(int j = i; j > left && arr[j]<arr[j-1];j--){
                exchange(arr[j], arr[j-1]);
            }
        }
        return;
    }
    int pivot1 = arr[left];
    exchange(arr[left+1], arr[right]);
    int pivot2 = arr[right];


    if(pivot2<pivot1)
        exchange(arr[pivot1], arr[pivot2]);

    int less = left + 1;
    int great = right -1;

    for(int k = less; k <= great; k++){
        //Less than P1//
        if(arr[k] < pivot1){
            exchange(arr[k], arr[less]);
            less++;
        }
        //Greater than P2//
        else if(arr[k] > pivot2){
            while(k < great && arr[great] > pivot2){
                great--;
            }
            exchange(arr[k], arr[great--]);
            if(arr[k] < pivot1){
                exchange(arr[k], arr[less++]);
            }
        }
    }

    int dist = great - less;

    if (dist < 13){
        div++;
    }

    exchange(arr[less-1], arr[left]);
    exchange(arr[great+1], arr[right]);

    dualPivotQuicksort(arr, left, less-2, div);
    dualPivotQuicksort(arr,  great+2, right, div);

    if(dist > len -13 && pivot1 != pivot2){
        for(int k = less; k <= great; k++){
            if(arr[k] == pivot1){
                exchange(arr[k], arr[less]);
                less++;
            }else if(arr[k] == pivot2){
                exchange(arr[k], less);
                less++;
            }
        }
    }

    if(pivot1 < pivot2){
        dualPivotQuicksort(arr, less, great, div);
    }
}

void randomdualPivotQuicksort(int arr[], int left, int right, int div){
    int len = right - left;
    if (len < 27){
        for(int i = left + 1; i <=right; i++){
            for(int j = i; j > left && arr[j]<arr[j-1];j--){
                exchange(arr[j], arr[j-1]);
            }
        }
        return;
    }
    int i1, i2 = 0;
    do{
        i1 = random_number(right);
        i2 = random_number(i1-1);
    }while(i1 == i2);
    //exchange(arr[left], arr[i1]);
    int pivot1 = arr[i1];
    //exchange(arr[i2], arr[right]);
    int pivot2 = arr[i2];


    if(pivot2<pivot1)
        exchange(arr[pivot1], arr[pivot2]);

    int less = left + 1;
    int great = right -1;

    for(int k = less; k <= great; k++){
        //Less than P1//
        if(arr[k] < pivot1){
            exchange(arr[k], arr[less]);
            less++;
        }
        //Greater than P2//
        else if(arr[k] > pivot2){
            while(k < great && arr[great] > pivot2){
                great--;
            }
            exchange(arr[k], arr[great--]);
            if(arr[k] < pivot1){
                exchange(arr[k], arr[less++]);
            }
        }
    }

    int dist = great - less;

    if (dist < 13){
        div++;
    }

    exchange(arr[less-1], arr[left]);
    exchange(arr[great+1], arr[right]);

    dualPivotQuicksort(arr, left, less-2, div);
    dualPivotQuicksort(arr,  great+2, right, div);

    if(dist > len -13 && pivot1 != pivot2){
        for(int k = less; k <= great; k++){
            if(arr[k] == pivot1){
                exchange(arr[k], arr[less]);
                less++;
            }else if(arr[k] == pivot2){
                exchange(arr[k], less);
                less++;
            }
        }
    }

    if(pivot1 < pivot2){
        dualPivotQuicksort(arr, less, great, div);
    }
}