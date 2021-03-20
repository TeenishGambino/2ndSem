/*
CH-231-A
a7_p1.cpp
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

//Lomoto//
void quickSort(int*, int, int);
int partition(int*, int, int);

//Hoare//
int Hpartition(int*, int, int);
void HquickSort(int*, int, int);

//Median-of-three//
int MedianOfThree(int*, int, int);

int MOTpartition(int*, int, int);

void MOTquickSort(int*, int, int);

//For array//

int random_number(int);

int * array_gen(int);
/*
int MOTpartitionH(int *, int, int);

void MOTquickSortH(int * , int, int);
*/

int main(void){
    ofstream Lomuto;
    ofstream Hoare;
    ofstream Median;
    //ofstream MedianH;

    Lomuto.open("Lomuto.txt");
    Hoare.open("Hoare.txt");
    Median.open("Median.txt");
    //MedianH.open("MedianH.txt");

    int size = 1000;
    int * arr = new int[size];
    int * arr1 = new int[size];
    int * arr2 = new int[size];
    //int * arr3 = new int[size];

    for (int i = 0; i < 10000; ++i){
        arr = array_gen(1000);
        for(int j = 0; j < size; ++j){
            //cout<<arr[j]<<" ";
            arr1[j] = arr[j];
            arr2[j] = arr[j];
            //arr3[j] = arr[j];
        }
        //cout<<endl;

        auto startLomuto = high_resolution_clock::now();
        quickSort(arr, 0, size-1);
        auto endLomuto = high_resolution_clock::now();
        auto timeLomuto = duration_cast<microseconds>(endLomuto-startLomuto);

        auto startHoare = high_resolution_clock::now();
        HquickSort(arr1, 0, size-1);
        auto endHoare = high_resolution_clock::now();
        auto timeHoare = duration_cast<microseconds>(endHoare-startHoare);

        auto startMedian = high_resolution_clock::now();
        MOTquickSort(arr2, 0, size-1);
        auto endMedian = high_resolution_clock::now();
        auto timeMedian = duration_cast<microseconds>(endMedian-startMedian);
        
        /*
        auto startMedianH = high_resolution_clock::now();
        MOTquickSortH(arr2, 0, size-1);
        auto endMedianH = high_resolution_clock::now();
        auto timeMedianH = duration_cast<microseconds>(endMedianH-startMedianH);
        */

        Lomuto<<i+1<<" "<<timeLomuto.count()<<endl;
        Hoare<<i+1<<" "<<timeHoare.count()<<endl;
        Median<<i+1<<" "<<timeMedian.count()<<endl;
        //MedianH<<i+1<<" "<<timeMedianH.count()<<endl;


    }
}



int partition(int * arr, int p, int q){
    int x = arr[p];
    int i = p;
    for(int j = p+1; j <= q; ++j){
        if(arr[j] <= x){
            i++;
            exchange(arr[i], arr[j]);
        }
    }
    exchange(arr[p], arr[i]);
    return i;
}

void quickSort(int * arr, int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
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

int Hpartition(int * arr, int p, int q){
    int index = (int)floor((p+q)/2);
    int pivot = arr[index];
    int i = p-1;
    int j = q+1;

    while(1){
        do{
            i++;
        }while(arr[i]<pivot);
        
        do{
            j--;
            //cout<<"lol"<<endl;
        }while(arr[j]>pivot);

        if(i>=j)
            return j;

        exchange(arr[i], arr[j]);
        
    }
}

void HquickSort(int * arr, int p, int r){
    if(p<r){
        int q = Hpartition(arr, p, r);
        HquickSort(arr, p, q);
        HquickSort(arr, q+1, r);
    }
}

int MedianOfThree(int * arr, int p, int r){
    int mid = (int)floor((p+r)/2);
    if (arr[mid] < arr[p])
        exchange(arr[p], arr[mid]);
    if(arr[r] < arr[p])
        exchange(arr[p], arr[r]);
    if(arr[mid] < arr[r])
        exchange(arr[mid], arr[r]);
    return (arr[r]);
}

int MOTpartition(int * arr, int p, int q){
    int x = MedianOfThree(arr, p, q);
    int i = p;
    for(int j = p+1; j <= q; ++j){
        if(arr[j] <= x){
            i++;
            exchange(arr[i], arr[j]);
        }
    }
    exchange(arr[p], arr[i]);
    return i;
}

void MOTquickSort(int * arr, int p, int r){
    if(p < r){
        int q = MOTpartition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int random_number(int size)
{
    int randomNumber;
    int number;

    //Uses system time for random number//
    //srand(static_cast<unsigned int>(time(0)));
    randomNumber = rand();

    number = (randomNumber%(size));

    return number;
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
/*
int MOTpartitionH(int * arr, int p, int q){
    int index = MedianOfThree(arr, p, q);
    int pivot = arr[index];
    int i = p-1;
    int j = q+1;

    while(1){
        do{
            i++;
        }while(arr[i]<pivot);
        
        do{
            j--;
            //cout<<"lol"<<endl;
        }while(arr[j]>pivot);

        if(i>=j)
            return j;

        exchange(arr[i], arr[j]);
    }
}

void MOTquickSortH(int * arr, int p, int r){
    if(p < r){
        int q = MOTpartition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}
*/

