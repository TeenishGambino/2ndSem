/*
CH-231-A
a2_p4.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    vector <int> values;
    vector <int>::iterator it;

    //Adding values to the vector//
    for (int i = 0; i < 30; i++)
    {
        values.push_back(i+1);
    }

    values.push_back(5);
    //Reverses//
    reverse(values.begin(), values.end());

    //Output//
    for (it = values.begin(); it != values.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //Replace//
    replace(values.begin(), values.end(), 5, 129);

    //Output with semicolon//
    for (it = values.begin(); it != values.end(); ++it)
    {
        cout<<*it;
        //Stops the last value from being ending with ;//
        if(it!=values.end()-1)
        {
            cout<<";";
        }
    }
    cout<<endl;

    return 0;
}

/*
    Note to self:
    The replace function only replaces specific valuecout<<*it;s. 
    Initally was expecting the value of 25 to be replaced with 2129
    But only "5" gets replaced. 
*/  