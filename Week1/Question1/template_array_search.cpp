#include<iostream>
#include<string>
#include"Complex.h"
#include<vector>

using namespace std;

template<typename T>
int array_search(T arr[], int number_of_elements, T item_to_find)
{
    /*Try using this later
    for(int i : arr)
    {
        if()
    }
    */ 
   for (int i = 0; i < number_of_elements; i++)
   {
       if(arr[i] == item_to_find)
       {
           return i;
       }
   }

   return -1;
}

int main(void)
{
    //Shows that Integer works//
    int data[] = {0, 1, 2, 3, 4};
    int size = sizeof(data)/sizeof(data[0]);
    int position = array_search(data, size, 4);
    cout<<"In integer the position is : "<<position<<endl;

    //Shows for double//
    double d_data[] = {1.2, 3.3};
    size = sizeof(d_data)/sizeof(d_data[0]); //How to optimise this?//
    position = array_search(d_data, size, 6.9);
    cout<<"In double the position is: "<<position<<endl;

    //Shows for char//
    char c_data[] = {'K', 'e', 'n', 'o', 'b', 'i'};
    size = sizeof(c_data)/sizeof(c_data[0]);
    position = array_search(c_data, size, 'o');
    cout<<"In char the position is: "<<position<<endl;
    
    //For Complex//
    Complex com_data[] = {Complex(1,-2), Complex(1,-1), Complex(6,9), Complex(-3,5)};
    size = sizeof(com_data)/sizeof(com_data[0]);
    position = array_search(com_data, size, Complex(1,-1));
    cout<<"In char the position is: "<<position<<endl; 
    

    return 0;
}


//Note to self://
/*Why won't it work in string?
    //Shows for string//
    string s_data[] = {"King", "Queen", "Rook", "Bishop", "Horse", "Pawn"};
    size = sizeof(s_data)/sizeof(s_data[0]);
    position = array_search(s_data, size, "Bishop");
    cout<<"In char the position is: "<<position<<endl;
*/ 

//Won't work, because a pointer is passed//
/*
template<typename T>
void sizer(T arr[])
{
    cout<<sizeof(arr);
   // return (sizeof(arr)/sizeof(T)); //Why does (sizeof(arr)/sizeof(T)); not work?//
}
*/