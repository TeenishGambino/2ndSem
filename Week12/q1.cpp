/*
CH-231-A
a12_p1.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Compare (const vector<int> &value1, const vector<int> &value2){
    return value1.size() < value2.size();
}

vector<int> LOS(vector<int> arr){
    int size = arr.size();

    //Stores previous subproblem suolutions//
    vector<vector<int> > table(size);
    //Used to point to vector with the longest subarray//
    vector<vector <int> >::iterator it;
    //Store first subarray sequence which is the first element in arr///
    table[0].push_back(arr[0]);
    
    //We check the other elements in the array//
    //i->other elements in the array//
    for(int i = 1; i < size; i++){
        for(int j = 0; j < size;j++){
            //We check if jcan be added and 
            //if adding it will increase the size of the subarray up until that point//
            //if not we continue building on the one we have already built//

            if (arr[i] > arr[j] && table[i].size() < table[j].size()){
                table[i] = table[j];
            }
        }
        table[i].push_back(arr[i]);
    }
    it = max_element(table.begin(), table.end(), Compare);
    return * it;
}

int main(){
    vector<int> arr;
    int temp;
    vector<int> longest;
    while(1){   
        cout<<"Enter value to add to sequence, add -1 to stop"<<endl;
        cin>>temp;
        if(temp<0){
            break;
        }
        arr.push_back(temp);
    }

    longest = LOS(arr);
    vector<int>::iterator it;
    for(it = longest.begin(); it!=longest.end();++it){
        cout<< *it<< " ";
    }
    cout<<endl; 
    
    return 0;
}