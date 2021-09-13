//
//  main.cpp
//  Permutations
//
//  Created by Federico Xu on 26/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getPermutations(vector<int> array);
void permutationsHelper(int pos, vector<int> &array, vector<vector<int>> &permutations);
void display(vector<vector<int>> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {1, 2, 3};
    display(getPermutations(array));
    return 0;
}


vector<vector<int>> getPermutations(vector<int> array){
    vector<vector<int>> permutations;
    permutationsHelper(0, array, permutations);
    return permutations;
}

void permutationsHelper(int pos, vector<int> &array, vector<vector<int>> &permutations){
    if(pos == array.size() - 1)
        permutations.push_back(array);
    else{
        for(int j = pos; j < array.size(); j++){
            swap(array[pos], array[j]);
            permutationsHelper(pos + 1, array, permutations);
            swap(array[j], array[pos]);
        }
    }
}

void display(vector<vector<int>> array){
    for(int i = 0; i < array.size(); i++){
        for(int j = 0; j < array[0].size(); j++)
            cout << array[i][j] << " ";
        cout << "\n";
    }
}
