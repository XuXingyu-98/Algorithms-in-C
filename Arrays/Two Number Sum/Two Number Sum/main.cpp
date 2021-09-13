//
//  main.cpp
//  Two Number Sum
//
//  Created by Federico Xu on 21/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {3, 5, -4, 8, 11, 1, -1, 6};
    int targetSum = 10;
    vector<int> results = twoNumberSum(array, targetSum);
    for(int i = 0; i < results.size(); i++)
        cout << results[i] << " ";
    cout << "\n";
}

vector<int> twoNumberSum(vector<int> array, int targetSum){
    unordered_set<int> numSet;
    for(int num: array){
        int potentialMatch = targetSum - num;
        if(numSet.find(potentialMatch) != numSet.end())
            return vector<int> {potentialMatch, num};
        else
            numSet.insert(num);
    }
    return {};
}
