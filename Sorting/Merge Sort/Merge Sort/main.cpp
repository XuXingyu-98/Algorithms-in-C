//
//  main.cpp
//  Merge Sort
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> array);
vector<int> mergeSortedArrays(vector<int> leftHalf, vector<int> rightHalf);
void display(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {8, 5, 2, 9, 5, 6, 3};
    vector<int> sorted = mergeSort(array);
    display(sorted);
    return 0;
}

vector<int> mergeSort(vector<int> array){
    if(array.size() <= 1)
        return array;
    
    int middle = array.size() / 2;
    vector<int> leftHalf(array.begin(), array.begin() + middle);
    vector<int> rightHalf(array.begin() + middle, array.end());
    return mergeSortedArrays(mergeSort(leftHalf), mergeSort(rightHalf));
}

vector<int> mergeSortedArrays(vector<int> leftHalf, vector<int> rightHalf){
    vector<int> merged(leftHalf.size() + rightHalf.size(), 0);
    int k = 0, i = 0, j = 0;
    while(i < leftHalf.size() && j < rightHalf.size()){
        if(leftHalf[i] <= rightHalf[j])
            merged[k++] = leftHalf[i++];
        else merged[k++] = rightHalf[j++];
    }
    
    while(i < leftHalf.size())
        merged[k++] = leftHalf[i++];
    
    while(j < rightHalf.size())
        merged[k++] = rightHalf[j++];
    
        return merged;
}

void display(vector<int> array){
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}
