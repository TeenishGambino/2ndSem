/*
CH-231-A
a1_p5.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    //The vector storing the words//
    vector <string> s_vector;
    //Used for the iterator//
    vector <string>::iterator it;
    //Stors the input value//
    string input;
    //Loops until end//
    while(1)
    {
        //cout<<"Input: ";
        getline(cin, input);

        //Breaking condition//
        if (input == "END")
        {
            break;
        }
        //Adds the word to vector//
        s_vector.push_back(input);
    }
    if(s_vector.size()>=5)
    {
        string temp = s_vector[1];
        s_vector[1] = s_vector[4];
        s_vector[4] = temp;
    }
    s_vector[s_vector.size()-1] = "???";

    //Printing words using index operator//
    for(int i = 0; i < s_vector.size(); i++ )
    {
        cout<<s_vector[i];
        if(i != s_vector.size()-1) 
        {
            cout<<",";
        }
    }
    cout<<endl;

    //Printing words using iterator//
    for (it = s_vector.begin(); it != s_vector.end();++it)
    {
        cout<<*it;
        if(it!=s_vector.end()-1)
        {
            cout<<";";
        }
    }
    cout<<endl;

    for (it = s_vector.end()-1; it >= s_vector.begin(); --it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}