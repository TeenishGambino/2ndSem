/*
CH-231-A
a3_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<array>
#include<ctime>
#include <fstream>
#include <chrono> //This library used for measuring execution time//
//#define n 5;


using namespace std;
using namespace chrono;

int random_number(int size)
{
    int randomNumber;
    int number;

    //Uses system time for random number//
    srand(static_cast<unsigned int>(time(0)));
    randomNumber = rand();

    number = (randomNumber%(size-1));

    return number;
}

void swap(int &value1, int &value2)
{
    int temp; 
    temp = value2;
    value2 = value1;
    value1 = temp;
}

void SelectionSort(int *values, int size)
{
    int i, j, min_index;

    for (i = 0; i < size-1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (values[j] > values[min_index])
            {
                min_index = j;
            }
            swap(values[j], values[min_index]);
        }
    }
}

int * array_gen(int size)
{
    int *arr = new int[size];
    for(int i = 1; i < size; i++)
    {
        arr[i] = random_number(size);
    }
    return arr;
}

int main(void)
{
    int *values;

    ofstream worst_f;
    worst_f.open("worst.txt");
    ofstream best_f;
    best_f.open("best.txt");
    ofstream av_f;
    av_f.open("average.txt");

    double average;
    double sum = 0;

    for(int i = 0; i < 5000; i = i + 10)
    {
        int size = i;
        //Generates a random array//
        values = array_gen(size);
        values[0] = size;
        //Case A//
        //The largest number at the start 
        //will produce the most swaps//
        
        auto start_worst = high_resolution_clock::now();
        SelectionSort(values, size);
        auto stop_worst = high_resolution_clock::now();
        auto time_worst = duration_cast<microseconds>(stop_worst-start_worst);
        //Case B//
        //The least number of swaps is when we already have a sorted
        //Array, since values is already sort //
        auto start_best = high_resolution_clock::now();
        SelectionSort(values, size);
        auto stop_best = high_resolution_clock::now();
        auto time_best = duration_cast<microseconds>(stop_best-start_best);
        //delete[] values;
        
        double sum = 0;
        int number_of_cases = 5;
        //For average case//
        for (int i = 0; i < number_of_cases; i++)
        {
            values = array_gen(i);
            auto start_average = high_resolution_clock::now();
            SelectionSort(values, size);
            auto stop_average = high_resolution_clock::now();
            auto time_average = duration_cast<microseconds>(stop_average-start_average);
            delete[] values;
            sum = sum + time_average.count();
        }
        average = sum / number_of_cases;

        worst_f<<size<<" "<<time_worst.count()<<endl;
        best_f<<size<<" "<<time_best.count()<<endl;
        av_f<<size<<" "<<average<<endl;
    }
    worst_f.close();
    best_f.close();
    av_f.close();
    return 0;
}