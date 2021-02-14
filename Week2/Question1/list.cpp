/*
CH-231-A
a2_p1.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/
#include<iostream>
#include<fstream>
#include<list>

using namespace std;

int main(void)
{
    list <int>A;
    list <int>B;
    ofstream output_file;
    output_file.open("listB.txt");

    if(!output_file)
    {
        cout<<"Could not create the file."<<endl;
        return 0;
    }

    int input;

    while(1)
    {
        cin>>input;
        if (input <= 0)
        {
            break;
        }
        A.push_back(input);
        B.push_front(input);

    }

    list <int>::iterator it;
    list<int>::iterator jt;
    for(it = A.begin(); it != A.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    for (jt = B.begin(); jt != B.end(); ++jt)
    {
        output_file<<*jt<<" ";
    }

    cout<<endl;
    it = A.begin();

    int temp = A.front();
    A.pop_front();
    A.push_back(temp);

    temp = B.front();
    
    it = B.begin();
    temp = B.front();
    B.erase(it);
    B.push_back(temp);

    //Could copy everything except for the first element into another list then add it back to list A//

    //int first = 
    int size = A.size();
    int i = 1;
    for (it = A.begin(); it != A.end(); ++it)
    {  
        cout<<*it;
        if(i < size)
        {
            cout<<",";
        }
        i++;
    }
    cout<<endl;
    size = B.size();
    i = 1;
    for (it = B.begin(); it != B.end(); ++it)
    {  
        cout<<*it;
        if(i < size)
        {
            cout<<",";
        }
        i++;
    }
    cout<<endl;
    
    A.merge(B);
    //SOrt how//
    A.sort();
    
    for(it = A.begin(); it != A.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    output_file.close();

    return 0;
}