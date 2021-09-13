//
//  main.cpp
//  Longest Peak
//
//  Created by Federico Xu on 23/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int longestPeak(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    cout << "The longest peak length is : " << longestPeak(array) << endl;
    return 0;
}

int longestPeak(vector<int> array){
    int longestPeakLength = 0;
    int i = 1;
    while(i <= array.size() - 2){
        bool isPeak = array[i - 1] < array[i] && array[i] > array[i + 1];
        if(!isPeak){
            i++;
            continue;
        }
        
        int left = i - 2;
        while(left >= 0 && array[left] < array[left + 1])
            left--;
        
        int right = i + 2;
        while(right <= array.size() - 1 && array[right] < array[right - 1])
            right++;
        
        int currentLength = right - left - 1;
        longestPeakLength = max(longestPeakLength, currentLength);
        
        i = right;
    }
    return longestPeakLength;
}
