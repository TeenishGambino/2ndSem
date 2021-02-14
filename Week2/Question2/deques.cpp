/*
CH-231-A
a2_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<deque>

using namespace std;

int main(void)
{
    deque <float> A;

    //These values are used to find if the
    //previous value was negative
    //and if the current value is positive//
    float previous, current;
    deque<float>::iterator it;

    //This is used to get input from the user//
    float input;

    //Continuous Input//
    while(1)
    {
        cin>>input;
        if (input == 0)
        {
            break;
        }
        else if(input>0)
        {
            A.push_back(input);
        }
        else
        {
            A.push_front(input);
        }
    }
    //Output//
    for (it = A.begin(); it != A.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    
    //Declare previous before the loop//
    it = A.begin();
    previous = *it;
    //Incrementing so that we start with the second value//
    ++it;

    for (; it != A.end(); ++it)
    {
        //Setting the current//
        current = *it;

        //Checking if previous is negative
        //and if current is position//
        if((previous < 0)&&(current > 0))
        {
            //Insert 0 in that position//
            A.insert(it, 0);
            break;
        }
        //Now the current becomes the previous//
        previous = current;
    }

    for (it = A.begin(); it != A.end(); ++it)
    {
        cout<<*it;

        //Stops ; being printed at the end//
        if(it!=A.end()-1)
        {
            cout<<";";
        }
    }
    cout<<endl;
    return 0;
}