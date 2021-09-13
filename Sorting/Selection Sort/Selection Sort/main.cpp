//
//  main.cpp
//  Selection Sort
//
//  Created by Federico Xu on 26/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &array);
void display(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {8, 5, 2, 9, 5, 6, 3};
    selectionSort(array);
    display(array);
    return 0;
}

void selectionSort(vector<int> &array){
    int startIdx = 0;
    while(startIdx < array.size() - 1){
        int smallestIdx = startIdx;
        for(int i = startIdx + 1; i < array.size(); i++)
            if(array[smallestIdx] > array[i])
                smallestIdx = i;
        swap(array[smallestIdx], array[startIdx]);
        startIdx++;
    }
}

void display(vector<int> array){
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}
