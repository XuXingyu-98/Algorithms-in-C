//
//  main.cpp
//  Four Number Sum
//
//  Created by Federico Xu on 23/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum);
void display(vector<vector<int>> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {7, 6, 4, -1, 1, 2};
    int targetSum = 16;
    display(fourNumberSum(array, targetSum));
    return 0;
}

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum){
    unordered_map<int, vector<vector<int>>> allPairSums;
    vector<vector<int>> quadruplets;
    for(int i = 1; i < array.size() - 1; i++){
        for(int j = i + 1; j < array.size(); j++){
            int currentSum = array[i] + array[j];
            int diff = targetSum - currentSum;
            if(allPairSums.find(diff) != allPairSums.end())
                for(vector<int> pair : allPairSums[diff]){
                    pair.push_back(array[i]);
                    pair.push_back(array[j]);
                    quadruplets.push_back(pair);
                }
        }
        for(int k = 0; k < i; k++){
            int currentSum = array[k] + array[i];
            if(allPairSums.find(currentSum) == allPairSums.end())
                allPairSums[currentSum] = vector<vector<int>> {{array[k], array[i]}};
            else
                allPairSums[currentSum].push_back(vector<int>{array[k], array[i]});
        }
    }
    return quadruplets;
}

void display(vector<vector<int>> array){
    for(int i = 0; i < array.size(); i++){
        for(int j = 0; j < array[0].size(); j++)
            cout << array[i][j] << " ";
        cout << "\n";
    }
}
