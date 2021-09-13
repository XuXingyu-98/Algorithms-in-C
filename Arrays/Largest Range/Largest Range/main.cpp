//
//  main.cpp
//  Largest Range
//
//  Created by Federico Xu on 24/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> largestRange(vector<int> array);
void display(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};
    display(largestRange(array));
    return 0;
}

vector<int> largestRange(vector<int> array){
    vector<int> bestRange = {};
    unordered_map<int, bool> nums = {};
    int longestLength = 0;
    for(int num: array)
        nums[num] = true;
    for(int num: array){
        if(!nums[num])
            continue;
        nums[num] = false;
        int currentLength = 1;
        int left = num - 1;
        int right = num + 1;
        while(nums.find(left) != nums.end()){
            nums[left] = false;
            currentLength++;
            left--;
        }
        while(nums.find(right) != nums.end()){
            nums[right] = false;
            currentLength++;
            right++;
        }
        
        if(currentLength > longestLength){
            longestLength = currentLength;
            bestRange = {left + 1, right - 1};
        }
    }
    return bestRange;
}

void display(vector<int> array){
    cout << array[0] << " " << array[1] << endl;
}
