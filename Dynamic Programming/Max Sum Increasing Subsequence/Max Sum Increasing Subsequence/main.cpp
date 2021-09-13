//
//  main.cpp
//  Max Sum Increasing Subsequence
//
//  Created by Federico Xu on 29/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> buildSequence(vector<int> array, vector<int> sequences, int currentIdx, int sum);
vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {10, 70, 20, 30, 50, 11, 30};
    vector<vector<int>> result = maxSumIncreasingSubsequence(array);
    cout << "The max sum is : " << result[0][0] << endl;
    for(int i = 0; i < result[1].size(); i++)
        cout << result[1][i] << " ";
    cout << endl;
    return 0;
}

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array){
    vector<int> sequences(array.size(), INT_MIN);
    vector<int> sums = array;
    int maxSumIdx = 0;
    for(int i = 0; i < array.size(); i++){
        int currentNum = array[i];
        for(int j = 0; j < i; j++){
            int otherNum = array[j];
            if(otherNum < currentNum && sums[j] + currentNum >= sums[i]){
                sums[i] = sums[j] + currentNum;
                sequences[i] = j;
            }
        }
        if(sums[i] >= sums[maxSumIdx])
            maxSumIdx = i;
    }
    return buildSequence(array, sequences, maxSumIdx, sums[maxSumIdx]);
}

vector<vector<int>> buildSequence(vector<int> array, vector<int> sequences, int currentIdx, int sum){
    vector<vector<int>> sequence = {{}, {}};
    sequence[0].push_back(sum);
    while(currentIdx != INT_MIN){
        sequence[1].insert(sequence[1].begin(), array[currentIdx]);
        currentIdx = sequences[currentIdx];
    }
    return sequence;
}
