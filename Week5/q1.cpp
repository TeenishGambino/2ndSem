/*
CH-231-A
a5_p1.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<ctime>
#include <fstream>
#include <chrono>
#include<cmath>
#include<vector>

#define power 1.4


using namespace std;
using namespace chrono;

double phi = (1+sqrt(5))/2;

//Recursive Method//
unsigned long long int recursive_fib(unsigned long long int n);
//Bottom up approach//
unsigned long long int bottom_fib(unsigned long long int n);
//Closed Form//
double closed_fib(int n);
int conv_closed_fib(int n); //coverts double to int//

/*Matrix implementation*/
//Multiplication//
int ** matrix_multi(int ** mat1, int ** mat2);
//Recursive part of it//
int ** matrix_imp(int n, int ** arr);
//Gives us the output//
int conv_matrix_imp(int n, int ** arr);

int main(void)
{
    int i = 0; 
    int value;
    int N[] = {0,1,2,3,4,5,6,8,10,13,16,20,25,32,40};
    double t_limit = 5000.0;
    clock_t start, end; 
    double time;
    unsigned long long int input = 0;
    //int i = 0;
    int ** arr = new int*[2];
    for(int j =0; j < 2; j++)
    {
        arr[j] = new int[2];
    }

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 0;

    int size = sizeof(N)/sizeof(N[0]);
    //cout<<size<<endl;

    // ofstream naive;
    // naive.open("Naive.txt");
    
    // do
    // {
    //     input = pow(i, power);
    //     auto start = high_resolution_clock::now();
    //     recursive_fib(input);
    //     auto stop = high_resolution_clock::now();
    //     auto change= duration_cast<microseconds>(stop-start);
    //     time = (double)change.count();
    //     if(time<t_limit)
    //         naive<<input<< " "<<time<<endl;
    //     ++i;
    // }while(time < t_limit);

    // naive.close();

    // ofstream bottom;
    // bottom.open("Bottom.txt");
    // i = 0;

    // do
    // {
    //     input = pow(i, power);
    //     auto start = high_resolution_clock::now();
    //     bottom_fib(input);
    //     auto stop = high_resolution_clock::now();
    //     auto change= duration_cast<microseconds>(stop-start);
    //     time = (double)change.count();
    //     if(time<t_limit)
    //         bottom<<input<< " "<<time<<endl;
    //     ++i;
    // }while(time < t_limit);

    //bottom.close();
    // ofstream phi;
    // phi.open("Closed.txt");
    // i = 0;
    // do
    // {
    //     input = pow(i, power);
    //     auto start = high_resolution_clock::now();
    //     closed_fib(input);
    //     auto stop = high_resolution_clock::now();
    //     auto change= duration_cast<microseconds>(stop-start);
    //     time = (double)change.count();
    //     phi<<input<< " "<<time<<endl;
    //     ++i;
    // }while(time < t_limit);

    // phi.close();
    ofstream matrix;
    matrix.open("Matrix.txt");
    i=0;

    do
    {
        input = pow(i, power);
        auto start = high_resolution_clock::now();
        conv_matrix_imp(input, arr);
        auto stop = high_resolution_clock::now();
        auto change= duration_cast<microseconds>(stop-start);
        time = (double)change.count();
        matrix<<input<< " "<<time<<endl;
        ++i;
    }while(time < t_limit);
    matrix.close();

    return 0;
}

unsigned long long int recursive_fib(unsigned long long int n){
    if (n==0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return recursive_fib(n-1)+recursive_fib(n-2);
    }
}

unsigned long long int bottom_fib(unsigned long long int n){
    vector<unsigned long long int> fib;
    fib.push_back(0);
    fib.push_back(1);

    for(int i = 2; i <= n; i++){
        fib.push_back(fib[i-1]+fib[i-2]);
    }
    return fib[n];
}
/*
int closed_fib(int n)
{
    long double value = (pow(phi, n))/sqrt(5);
    int value_int = round(value);
    return value_int;
}
*/

double closed_fib(int n){
    if(n==0){
        return (1/sqrt(5));
    }
    else if (n == 1){
        return (phi/sqrt(5));
    }
    else{
        return phi * closed_fib(n-1);
    }
}

int conv_closed_fib(int n){
    double value = closed_fib(n);
    return round(value);
}

int ** matrix_multi(int ** mat1, int ** mat2){
    //Output array//
    int ** arr = 0;
    arr = new int*[2];
    for(int i = 0; i < 2; i++){
        arr[i] = new int[2];
    }

    arr[0][0] = mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0];
    arr[0][1] = mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1];
    arr[1][0] = mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0];
    arr[1][1] = mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1];
   
    return (int **)arr;
}

int ** matrix_imp(int n, int ** arr){
    if(n == 0){
        arr[0][0] = 0;
        arr[0][1] = 0;
        arr[1][0] = 0;
        arr[1][1] = 0;

        return (int **) arr;
    }
    else if (n == 1 || n == 2){
        return (int **) arr;
    }
    else{
        return (int **) matrix_multi(arr, matrix_imp(n-1, arr));
    }
}

int conv_matrix_imp(int n, int ** arr){
    //So that the main array is not change//
    //temporary array//
    int ** temp = new int*[2];
    for (int i = 0; i < 2; i++){
        temp[i] = new int[2];
    }

    //Copy value//
    for(int i = 0; i < 2;i++){
        for(int j =0; j < 2; j++){
            temp[i][j] = arr[i][j];
        }
    }
    
    int ** values = matrix_imp(n, temp);
    //Need this, without this, get segmentation fault, probably because im deleting temp//
    int a = values[0][0];

    for(int i = 0; i < 2; i++){
        delete[] temp[i];
    }
    delete[] temp;
    return a;
}