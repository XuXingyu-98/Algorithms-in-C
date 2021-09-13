//
//  main.cpp
//  Bubble Sort
//
//  Created by Federico Xu on 26/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &array);
void display(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {8, 5, 2, 9, 5, 6, 3};
    bubbleSort(array);
    display(array);
    return 0;
}

void bubbleSort(vector<int> &array){
    bool isSorted = false;
    int count = 0;
    while(!isSorted){
        isSorted = true;
        for(int i = 0; i < array.size() - 1 - count; i++){
            if(array[i] > array[i + 1]){
                swap(array[i], array[i + 1]);
                isSorted = false;
            }
        }
        count++;
    }
}

void display(vector<int> array){
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}
