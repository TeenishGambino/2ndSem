/*
CH-231-A
a2_p6.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/
#include<iostream>
#include<map>
#include<algorithm>
#include <fstream>

using namespace std;

int main(void)
{
    string temp_name;
    string temp_date;
    string name = "Albert Einstein";
    ifstream input_file;
    input_file.open("data.txt");
    map<string, string> name_b;
    map<string, string>::iterator it;

    if(!input_file)
    {
        cout<<"Could not create the file."<<endl;
        return 0;
    }

    while(!input_file.eof())
    {

        getline(input_file,temp_name);
        getline(input_file, temp_date);
        //cout<<temp_name;
        //cout<<temp_date<<endl;
        name_b.insert({temp_name, temp_date});
    }
    it = name_b.find(name);
    if(name_b.find(name) != name_b.end())
    {
        cout<<name<<" has a birthday on "<<it->second<<endl;
    }
    return 0;
}