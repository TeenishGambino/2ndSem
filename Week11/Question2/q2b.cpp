/*
CH-231-A
a11_p1.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<set>
#include<vector>
#include<list>

using namespace std;

class item{
    public:
        int start;
        int finish;

    friend ostream& operator << (ostream& out, const item& temp){
        out<<"{"<<temp.start<<" "<<temp.finish<<"}"<<endl;
        return out;
    }
};

list<item> Greedy(item * A, int start, int finish, int n_items){
    //cout<<"AAA"<<endl;
    list<item> v;
    int max = 0;
    int count = -1;
    for(int i = 0; i < n_items; i++){
        
        if(A[i].finish > finish || A[i].start > finish){
            continue;
        }
        if(A[i].finish > max){
            //cout<<A[i].start<<"LOL"<<endl;
            max = A[i].finish; 
            count = i;
        }
    }
    //Base condition//
    if(count == -1){
        
        item temp;
        temp.finish = 0;
        temp.start = 0;
        v.push_back(temp);
        return v;
    }
    v = Greedy(A, start, A[count].start, n_items);
    v.push_back(A[count]);
    return v;
    
}

int main(void){
    list<item> test;
    item A[6];
    list<item>::iterator it;
    int s[] =  {8, 0, 5, 3, 5, 1};
    int f[] =  {9, 6, 7, 4, 9, 2};
    
    for(int i =0; i < 6; i++){
        item temp;
        temp.start = s[i];
        temp.finish = f[i];
        A[i] = temp;
    }
    test = Greedy(A, 0, 10, 6);
    //Used to remove {0,0}, which were the base condition//
    test.pop_front();

    for(it = test.begin(); it != test.end(); ++it){
        cout << *it;
    }

    return 0;
}