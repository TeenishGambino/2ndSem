/*
CH-231-A
a4_p1.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<ctime>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

void print(int A[], int size);

void insertionSort(int arr[], int p, int r)
{
    int current;
    int j;
    for (int i = p+1; i <= r; i++)
    {
        current = arr[i];
        j = i - 1;
        while( j >= p && arr[j] > current)
        {
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = current;
    }
}

void mergeAlgorithm(int arr[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[q + 1 + j];

	int i = 0;
	int j = 0;
	int k = p;

    //for(;i < n1 && j < n2;k++ )
    while(i < n1 && j < n2)
    {
		if (L[i] <= R[j]) 
        {
			arr[k] = L[i];
			i++;
		}
		else 
        {
			arr[k] = R[j];
			j++;
		}
        k++;
	}

	while (i < n1) 
    {
		arr[k] = L[i];
		i++;
		k++;
    }
	while (j < n2) 
    {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// p is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int p,int r, int k)
{
    //print(arr, r+1); 
    if((r - p)<= k)
    {
        insertionSort(arr, p, r);
        //print(arr, r+1);
    }
   else 
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q, k);
        mergeSort(arr, q + 1, r, k);
        mergeAlgorithm(arr, p, q, r);
    }
}

// Function to print an array
void print(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
    cout<<endl;
}

int random_number(int size)
{
    int randomNumber;
    int number;

    //Uses system time for random number//
    srand((time(NULL)));
    randomNumber = rand();

    number = (randomNumber%size);

    return number;
}

//Worst case is when the array values are decreasing,
int * array_worst(int size)
{
    int *arr = new int[size];
    
    for(int i = 0; i < size; i++ )
    {
        arr[i] = size - i;
    }
    return arr;
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

int main()
{ 
    ofstream worst_f;
    worst_f.open("worst.txt");
    ofstream best_f;
    best_f.open("best.txt");
    ofstream av_f;
    av_f.open("average.txt");

    int size = 1000;
    int arr[size];

    for(int k = 0; k < size; k = k + 10)
    {
        //For average case//

        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % size;
        }

        auto start_average = high_resolution_clock::now();
        mergeSort(arr, 0, size-1, k);
        //print(arr, size);
        auto stop_average = high_resolution_clock::now();
        auto time_average = duration_cast<microseconds>(stop_average-start_average);
     

        for(int i = 0; i < size; i++ )
        {
            //cout<<i<<"a\n";
            //values[i] = size - i;
            arr[i] = size - i;
        }
        //Worst case is when the array values are decreasing,
        //and we are using insertion sort n/k = 1//
        //print(arr, size);
        auto start_worst = high_resolution_clock::now();
        mergeSort(arr, 0, size-1, k);
        //print(arr, size);
        auto stop_worst = high_resolution_clock::now();
        auto time_worst = duration_cast<microseconds>(stop_worst-start_worst);
        
        for (int i = 0; i < size; i++)
        {
            arr[i] = i;
        }
        //Best case senario, is when the the array is sorted//
        //Array, since values is already sort //
        auto start_best = high_resolution_clock::now();
        mergeSort(arr, 0, size-1, k);
        auto stop_best = high_resolution_clock::now();
        auto time_best = duration_cast<microseconds>(stop_best-start_best);

        worst_f<<k<<" "<<time_worst.count()<<endl;
        best_f<<k<<" "<<time_best.count()<<endl;
        av_f<<k<<" "<<time_average.count()<<endl;
    }
	return 0;
}

