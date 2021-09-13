//
//  main.cpp
//  Max Subset Sum No Adjacent
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {75, 105, 120, 75, 90, 135};
    cout << maxSubsetSumNoAdjacent(array) << endl;
    return 0;
}

int maxSubsetSumNoAdjacent(vector<int> array){
    if(array.size() == 0)
        return 0;
    else if (array.size() == 1)
        return array[0];
    
    vector<int> maxSums = array;
    maxSums[1] = max(array[0], array[1]);
    for(int i = 2; i < array.size(); i++)
        maxSums[i] = max(maxSums[i - 1], maxSums[i - 2] + array[i]);
    return maxSums[array.size() - 1];
}
