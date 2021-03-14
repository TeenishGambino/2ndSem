/*
CH-231-A
a6_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/
#include<iostream>
#include<vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;
//Normal Implementation of HeapSort//
void HeapSort(int[], int);
void BuildMaxHeap(int[], int);
void MaxHeapify(int[], int, int);

//Bottom Up//
void BottomUpHeapSort(int[], int);
void BottomUp(int[], int, int);
int LeafSearch(int[], int, int);
int target(int[], int, int);

//Helper functions//
void exchange(int &a, int &b);
void printer(int[], int);


int main(void){

    int size = 100000;
    int arr[size];
    int arr2[size];
    ofstream bottom;
    bottom.open("Bottom.txt");
    ofstream regular;
    regular.open("Regular.txt");

    for(int k = 0; k < size; k = k + 10)
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % size;
            arr2[i] = arr[i];
        }

        auto rstart_average = high_resolution_clock::now();
        HeapSort(arr, k);
        auto rstop_average = high_resolution_clock::now();
        auto rtime_average = duration_cast<microseconds>(rstop_average-rstart_average);
        
        regular<<k<<" "<<rtime_average.count()<<endl;

        auto bstart_average = high_resolution_clock::now();
        BottomUpHeapSort(arr2, k);
        auto bstop_average = high_resolution_clock::now();
        auto btime_average = duration_cast<microseconds>(bstop_average-bstart_average);

        bottom<<k<<" "<<btime_average.count()<<endl;
    }

    regular.close();
    bottom.close();

}

void HeapSort(int arr[], int size){
    BuildMaxHeap(arr, size);

    //Extract element from heap//
    for(int i = size-1; i>0; i--){
        //Move current root to end//
        exchange(arr[0], arr[i]);
        size--;
        //Reduce heap//
        MaxHeapify(arr, 0, size);
    }
}

//Builds Heap//
void BuildMaxHeap(int arr[], int size){
    //int length = size;

    for(int i = size/2; i >= 0;i--){
        MaxHeapify(arr, i, size);
    }
}

void MaxHeapify(int arr[], int i, int size){
    int l = 2*i;
    int r = 2*i+1;
    int largest;

    //if left child greater than root//
    if(l < size && arr[l]>arr[i])
        largest = l;
    else 
        largest = i;
    //if right child is larger then the largest so far//
    if(r<size && arr[r]>arr[largest])
        largest = r;
    //if largest is not root//
    if(largest != i){
        exchange(arr[i], arr[largest]);
        MaxHeapify(arr, largest, size);
    }
}

//Used in swapping//
void exchange(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//Prints array//
void printer(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void BottomUpHeapSort(int arr[], int size){
        BuildMaxHeap(arr, size);
        for(int i = size-1; i>0; i--){
        //Move current root to end//
        exchange(arr[0], arr[i]);
        size--;
        //Reduce heap//
        BottomUp(arr, 0, size);
        }
}


void BottomUp(int arr[], int i, int size){
    //Leaf Node - Node at the bottom//
    int leafN = LeafSearch(arr, i, size);
    //Node that is smaller than root//
    int Node = target(arr, i, leafN);

    if(i == Node)
        return;
    //Putting the root value where node was//
    int NodeValue = arr[Node];
    arr[Node] = arr[i];

    while(Node > i){
        //Parent of node//
        int parent = (Node -1)/2;
        int pValue = arr[parent];
        //Swaps parent of node with node//
        arr[parent] = NodeValue;
        //The node has been swapped is
        //So we need to change Node value
        Node = (Node -1)/2;
        NodeValue = pValue;
    }
}

//Finds the largest value in the bottom node
//and swaps that with root//
int LeafSearch(int arr[], int i, int size){
    int j = i;
    int right = 2*j+2;
    int left = 2*j+1;
   while(right < size){
       if(arr[right]>arr[left])
           j = right;
       else
            j = left;

        left = j *2 +1;
        right = j*2+2;
       
   }
    return j;
}

//Search from bottom to top
//For the first element smaller than root//
//i is the root node//
int target(int arr[], int i, int leaf){
    int parent  = arr[i];
    while(leaf != i && arr[leaf]<parent)
        leaf = (leaf-1)/2;
    return leaf;
}