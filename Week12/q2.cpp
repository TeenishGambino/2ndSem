/*
CH-231-A
a12_p2.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
enum lr {L, R};


//Tried to use arrays, but to calculate the size is annoying, hence vectors//

int maxPath(vector<vector<int>> tri, vector<vector<lr>> &path){
    
    for(int i = (int) tri.size()-2; i>= 0; i--){
        for(int j = 0; j <= i; j++){
            if(tri[i+1][j] > tri[i+1][j+1]){
                tri[i][j] = tri[i][j] + tri[i+1][j];
            }else{
                tri[i][j] = tri[i][j] + tri[i+1][j+1];
            }

            path[i][j] = tri[i+1][j]>tri[i+1][j+1] ? L : R;
        }
    }
    return tri[0][0];
}

vector<int> traversal(vector<vector<int>> tri, vector<vector<lr>> &path){
    int Location = 0;
    vector<int> best_path;
    for(int i =0; i < (int) tri.size(); i++){
        best_path.push_back(tri[i][Location]);
        if(path[i][Location] == R)
            Location++;
    }

    return best_path;
}

int main(void){
    int in;
    int row = 0, col = 0, sum = 0;
    vector<vector<int>> input;
    vector<vector<lr>> paths;
    //It is used for //
    vector<int> path, empty;
    vector<lr> emptychoice;

    input.push_back(empty);
    paths.push_back(emptychoice);

    cin>>in;
    while(in > -1 && in < 10001){
        if(col>row){
            col = 0; 
            input.push_back(empty);
            paths.push_back(emptychoice);
            row++;
        }
        input[row].push_back(in);
        paths[row].push_back({});
        cin>>in;
        col++;
    }    

    sum = maxPath(input, paths);
    path = traversal(input, paths);

    cout<<sum<<endl;

    for(int element : path)
        cout<<element<<" ";
    cout<<endl;
    return 0;
}