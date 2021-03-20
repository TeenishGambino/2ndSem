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
int w = 10;

/*Utility function*/
//Used for swapping values//
void exchange(int &a, int &b);
//Prints array//
void printer(int[], int );
int * array_gen(int size);
int random_number(int size);
void dualPivotQuicksort(int arr[], int left, int right, int div);



void sort(int arr[], int low, int high){
    //exchange(arr[low+1], arr[high]);
    if(high<=low){
        return;
    }
    int pivot1 = arr[low];
    exchange(arr[low+1], arr[high]);
    int pivot2 = arr[high];

    //exchange(arr[low+1], arr[high]);

    if(pivot1>pivot2){
        exchange(arr[low], arr[high]);
        pivot1 = arr[low];
        pivot2 = arr[high];
    }else if(pivot1 == pivot2){
        while(pivot1 == pivot2 && low < high){
            low++;
            pivot1 = arr[low]; 
        }

    }

    int i = low+1;
    int lt = low +1;
    int gt = high -1;

    while(i <= gt){
        if(arr[i] < pivot1){
            exchange(arr[i++], arr[lt++]);
        }else if(pivot2<arr[i]){
            exchange(arr[i], arr[gt--]);
        }
        else{
            i++;
        }
    } 

    exchange(arr[low], arr[--lt]);
    exchange(arr[high], arr[++gt]);

    sort(arr, low, lt-1);
    sort(arr, lt+1, gt-1);
    sort(arr, gt+1, high);
}
int main(void){
    int size = 35;
    int * arr = new int[size];

    arr = array_gen(size);
    //int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before: "<<endl;
    printer(arr, size);
    cout<<"After: "<<endl;
    dualPivotQuicksort(arr, 0, size-1,3);
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

    //Uses system time for random number//
    //srand(static_cast<unsigned int>(time(0)));
    randomNumber = rand();

    number = (randomNumber%(size));

    return number;
}



void dualPivotQuicksort(int arr[], int left, int right, int div){
    //exchange(arr[left+1], arr[right]);//the second pivot is moved to the end//
    int len = right - left;
    if (len < 27){
        for(int i = left + 1; i <=right; i++){
            for(int j = i; j > left && arr[j]<arr[j-1];j--){
                exchange(arr[j], arr[j-1]);
            }
        }
        return;
    }
    //cout<<"aaaa"<<endl;

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

/*
void dualPivotQuicksort(int arr[], int left, int right){
    if(right <= left){
        return;
    }
    int len = right - left;
    if(len < TINY_SIZE){
        for(int i = left+1; i <= right; i++){
            for(int j = i; j > left && arr[j] < arr[j-1]; j--){
                exchange(arr[j-1], arr[j]);
            }
        }
        return;
    }

    int sixth = len/6;
    int m1 = left + sixth;
    int m2 = m1+sixth;
    int m3 = m2 + sixth;
    int m4 = m3 + sixth;
    int m5 = m4 + sixth;

    if(arr[m1] > arr[m2])
        exchange(arr[m1], arr[m2]);
    if(arr[m4] > arr[m5])
        exchange(arr[m4], arr[m5]);
    if(arr[m1] > arr[m3])
        exchange(arr[m1], arr[m3]);
    if(arr[m2] > arr[m3])
        exchange(arr[m2], arr[m3]);
    if(arr[m1] > arr[m4])
        exchange(arr[m1], arr[m4]);
    if(arr[m3] > arr[m4])
        exchange(arr[m3], arr[m4]);
    if(arr[m2] > arr[m5])
        exchange(arr[m2], arr[m5]);
    if(arr[m2] > arr[m3])
        exchange(arr[m2], arr[m3]);
    if(arr[m4] > arr[m5])
        exchange(arr[m4], arr[m5]);
    
    int pivot1 = arr[m2];
    int pivot2 = arr[m4];

    //bool diffPivots = pivot1 != pivot2;
    arr[m2] = arr[left];
    arr[m4] = arr[right];

    int less = left+1;
    int great = right -1;
    int temp;
    if(pivot1 != pivot2){
        for(int k = less; k <=great; k++){
            temp = arr[k];
            if(temp < pivot1){
                arr[k] = arr[less];
                arr[less++] = temp;
            }else if (temp > pivot2){
                while(arr[great] > pivot2 && k < great){
                    great--;
                }
                arr[k] = arr[great];
                arr[great--] = temp;
                temp = arr[k];

                if (temp < pivot1){
                    arr[k] = arr[less];
                    arr[less++] = temp;
                }
            }
    
        }
    }else{
        for(int k = less; k <= great; k++){
            temp = arr[k];

            if(temp == pivot1){
                continue;
            }
            if(temp < pivot1){
                arr[k] = arr[less];
                arr[less++] = temp;
            }else{
                while(arr[great] > pivot2 && k < great){
                    great--;
                }
                arr[k] = arr[great];
                arr[great--] = temp;
                temp = arr[k];

                if(temp < pivot1){
                    arr[temp] = arr[less];
                    arr[less++] = temp;
                }
            }
        }
        arr[left] = arr[less -1];
        arr[less -1]= pivot1;

        arr[right] = arr[great+1];
        arr[great+1] = pivot2;

        dualPivotQuicksort(arr, left, less-2);
        dualPivotQuicksort(arr, great+2, right);

        if(great - less > len - DIST_SIZE && pivot1 != pivot2){
            for(int k = less; k <= great; k++){
                temp = arr[k];
                if(temp == pivot1){
                    arr[k] = arr[less];
                    arr[less++] = temp;
                }else if(temp == pivot2){
                    arr[k] = arr[great];
                    arr[great--] = temp;
                    temp = arr[k];

                    if(temp == pivot1){
                        arr[k] = arr[less];
                        arr[less++] = temp;
                    }
                }
            }
        }
        if(pivot1 != pivot2)
            dualPivotQuicksort(arr,less,great);
    }
}
*/