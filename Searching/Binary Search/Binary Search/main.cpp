//
//  main.cpp
//  Binary Search
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target);
int binarySearchHelper(vector<int> array, int target, int left, int right);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {0, 1, 21, 33, 45, 45, 61, 71, 72, 73};
    int target = 33;
    cout << binarySearch(array, target) << endl;
    return 0;
}

int binarySearch(vector<int> array, int target){
    return binarySearchHelper(array, target, 0, array.size() - 1);
}

int binarySearchHelper(vector<int> array, int target, int left, int right){
    if(left > right)
        return -1;
    
    int middle = (left + right) / 2;
    int potentialMatch = array[middle];
    if(target == potentialMatch)
        return middle;
    else if (target > potentialMatch)
        return binarySearchHelper(array, target, middle + 1, right);
    else
        return binarySearchHelper(array, target, left, middle - 1);
    
}
