/*
CH-231-A
a3_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/
#include <iostream>
using namespace std;

void print(int A[], int size);
//I used this as a gobal value for k//
int jeff;
// Merges two subarrays of arr[].
// First subarray is arr[0..q]
// Second subarray is arr[q+1..r]

/*
    p is a variable which helps index arr[], and add item to 
    the left temporary array

    q is a variable which helps index arr[]. and add items to
    the right temporary array 
*/

void insertionSort(int arr[], int p, int r)
{
    int current;
    int j;
    //cout<<"=======";
    //print(arr, r);
    for (int i = p; i <= r; i++)
    {
        current = arr[i];
        j = i - 1;
        while( j >= 0 && arr[j] > current)
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

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[q + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = p;

    //This is used to merge the array in order//
    for(;i < n1 && j < n2;k++ )
    {
		if (L[i] <= R[j]) 
        {
			arr[k] = L[i];
            //Increases the index of array in left array//
			i++;
		}
		else 
        {
			arr[k] = R[j];
            //Increases the index of array in right array//
			j++;
		}
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
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
    
    //Because q essentially tells us the size of array//
   //cout<<"r: "<<r<<endl;
    //cout<<"this: "<<r-p<<endl;
    print(arr, r+1);
    
    if((r-p)<= k)
    {
        //cout<<"lol"<<r+1<<r-p<<endl;
        //mergeAlgorithm(arr, p, q, r);
        insertionSort(arr, p, r);
        //return;
        //print(arr, r+1);
    }
   else if (r > p)
    {
        //cout<<"BBBBBBB"<<endl;
        int q = (p+r)/2;
        mergeSort(arr, p, q, k);
        //cout<<"aaaaaaa"<<endl;
        //q+1, because we want the element after the middle//
        mergeSort(arr, q+1, r, k);
        /*
        if(jeff == q)
        {
            insertionSort(arr, r+1);
        }*/
        
        //insertionSort(arr, q+1, r);
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

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
    int k = 1;
	cout << "Given array is \n";
    //cout<<arr_size;
	//print(arr, arr_size);
    jeff = arr_size/k; 

	mergeSort(arr, 0, arr_size - 1, k);

	cout << "Sorted array is \n";
	print(arr, arr_size);
	return 0;
}

