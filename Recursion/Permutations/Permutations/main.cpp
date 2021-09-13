//
//  main.cpp
//  Permutations
//
//  Created by Federico Xu on 31/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getPermutations(vector<int> array);
void permutationsHelper(int i, vector<int> &array, vector<vector<int>> &permutations);

int main(int argc, const char * argv[]) {
    vector<int> array = {1, 2, 3};
    vector<vector<int>> permutations = getPermutations(array);
    for(int i = 0; i < permutations.size(); i++){
        for(int j = 0; j < permutations[i].size(); j++)
            cout << permutations[i][j] << " ";
        cout << endl;
    }
    return 0;
}

vector<vector<int>> getPermutations(vector<int> array){
    vector<vector<int>> permutations;
    permutationsHelper(0, array, permutations);
    return permutations;
}

void permutationsHelper(int i, vector<int> &array, vector<vector<int>> &permutations){
    if(i == array.size() - 1)
        permutations.push_back(array);
    else{
        for(int j = i; j < array.size(); j++){
            swap(array[i], array[j]);
            permutationsHelper(i + 1, array, permutations);
            swap(array[i], array[j]);
        }
    }
}
