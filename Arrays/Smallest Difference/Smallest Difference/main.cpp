//
//  main.cpp
//  Smallest Difference
//
//  Created by Federico Xu on 21/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arrayOne = {-1, 5, 10, 20, 28, 3};
    vector<int> arrayTwo = {26, 134, 135, 15, 17};
    vector<int> results = smallestDifference(arrayOne, arrayTwo);
    cout << results[0] << " " << results[1] << endl;
    return 0;
}

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo){
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    int idOne = 0, idTwo = 0;
    int smallest = INT_MAX, current;
    vector<int> smallestPair;
    while(idOne < arrayOne.size() && idTwo < arrayTwo.size()){
        int first = arrayOne[idOne];
        int second = arrayTwo[idTwo];
        if(first > second){
            current = first - second;
            idTwo++;
        }else if(first < second){
            current = second - first;
            idOne++;
        }else
            return {first, second};
        if(smallest > current){
            smallest = current;
            smallestPair = {first, second};
        }
    }
    return smallestPair;
}
