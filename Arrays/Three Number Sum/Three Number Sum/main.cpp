//
//  main.cpp
//  Three Number Sum
//
//  Created by Federico Xu on 21/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {12, 3, 1, 2, -6, 5, -8, 6};
    int targetSum = 0;
    vector<vector<int>> results = threeNumberSum(array, targetSum);
    for(int i = 0; i< results.size(); i++){
        for(int j = 0; j < 3; j++)
            cout << results[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum){
    sort(array.begin(), array.end());
    vector<vector<int>> triplets;
    for(int i = 0; i< array.size() - 2; i++){
        int left = i + 1;
        int right = array.size() - 1;
        while(left < right){
            int currentSum = array[i] + array[left] + array[right];
            if(currentSum == targetSum){
                triplets.push_back({array[i], array[left], array[right]});
                right--;
                left++;
            }else if(currentSum < targetSum)
                left++;
            else
                right--;
        }
    }
    return triplets;
}
