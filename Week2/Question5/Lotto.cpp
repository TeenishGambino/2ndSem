/*
CH-231-A
a2_p5.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#include<ctime>

using namespace std;

int random_number()
{
    int randomNumber;
    int number;

    //Uses system time for random number//
    srand(static_cast<unsigned int>(time(0)));
    randomNumber = rand();

    number = (randomNumber%49+1);

    return number;
}

int main(void)
{   
    set<int> numbers;
    set<int>::iterator it;
    
    int size = 0;

    //For the test a size of 10 number will be drawn//
    while(size < 10)
    {
        //Used to store the 6 values//
        vector<int> six;
        for (int i = 0; i < 6; i++)
        {
            six.push_back(random_number());
        }
        //Total of the six values//
        int total = accumulate(six.begin(), six.end(), 0);
        
        //Condition to check if the total is in the set or not//
        //if it is then we start from beginning//
        if(numbers.find(total) != numbers.end())
        {
            continue;
        }
        else
        {
            numbers.insert(total);
            size++;
        }
    }

    //Output//
    for(it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}