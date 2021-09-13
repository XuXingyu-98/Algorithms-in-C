//
//  main.cpp
//  Powerset
//
//  Created by Federico Xu on 31/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array);

int main(int argc, const char * argv[]) {
    vector<int> array = {1, 2, 3};
    vector<vector<int>> Powerset = powerset(array);
    for(int i = 0; i < Powerset.size(); i++){
        cout << "{ ";
        for(int j = 0; j < Powerset[i].size(); j++)
            cout << Powerset[i][j] << " ";
        cout << "}" << endl;
    }
    return 0;
}

vector<vector<int>> powerset(vector<int> array){
    vector<vector<int>> subsets = {{}};
    for(int ele : array){
        int length = subsets.size();
        for(int i = 0; i < length; i++){
            vector<int> currentSubset = subsets[i];
            currentSubset.push_back(ele);
            subsets.push_back(currentSubset);
        }
    }
    return subsets;
}
