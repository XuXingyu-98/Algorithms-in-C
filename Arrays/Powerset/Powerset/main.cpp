//
//  main.cpp
//  Powerset
//
//  Created by Federico Xu on 26/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array);
void display(vector<vector<int>> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {1, 2, 3};
    display(powerset(array));
    return 0;
}

vector<vector<int>> powerset(vector<int> array){
    vector<vector<int>> subsets = {{}};
    for(int el : array){
        int length = subsets.size();
        for(int i = 0; i < length; i++){
            vector<int> currentSubset = subsets[i];
            currentSubset.push_back(el);
            subsets.push_back(currentSubset);
        }
    }
    return subsets;
}

void display(vector<vector<int>> array){
    for(int i = 0; i < array.size(); i++){
        cout << "{ ";
        for(int j = 0; j < array[i].size(); j++)
            cout << array[i][j] << " ";
        cout << "}" << endl;
    }
}
