//
//  main.cpp
//  QuickSort
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &array);
void quickSortHelper(vector<int> &array, int startIdx, int endIdx);
void display(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {8, 5, 2, 9, 5, 6, 3};
    quickSort(array);
    display(array);
    return 0;
}

void quickSort(vector<int> &array){
    quickSortHelper(array, 0, array.size() - 1);
}

void quickSortHelper(vector<int> &array, int startIdx, int endIdx){
    if(startIdx >= endIdx)
        return;
    int pivot = startIdx;
    int left = startIdx + 1;
    int right = endIdx;
    while(left <= right){
        if(array[left] > array[pivot] && array[pivot] > array[right])
            swap(array[left], array[right]);
        
        if(array[left] <= array[pivot])
            left++;
        
        if(array[right] >= array[pivot])
            right--;
    }
    swap(array[pivot], array[right]);
    quickSortHelper(array, startIdx, right - 1);
    quickSortHelper(array, right + 1, endIdx);
}

void display(vector<int> array){
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}
