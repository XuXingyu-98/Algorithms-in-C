//
//  main.cpp
//  Validate Subsequence
//
//  Created by Federico Xu on 21/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence);

int main(int argc, const char * argv[]) {
    vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> sequence = {1, 6, -1, 10};
    if(isValidSubsequence(array, sequence))
        cout << "OK!\n";
    return 0;
}

bool isValidSubsequence(vector<int> array, vector<int> sequence){
    int arrId = 0, seqId = 0;
    for(arrId = 0; arrId < array.size() && seqId < sequence.size(); arrId++)
        if(array[arrId] == sequence[seqId])
            seqId++;
    return seqId == sequence.size();
}
