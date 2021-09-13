//
//  main.cpp
//  Insertion Sort
//
//  Created by Federico Xu on 26/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &array);
void display(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {8, 5, 2, 9, 5, 6, 3};
    insertionSort(array);
    display(array);
    return 0;
}

void insertionSort(vector<int> &array){
    for(int i = 1; i < array.size(); i++){
        int j = i;
        while(j > 0 && array[j] < array[j - 1]){
            swap(array[j], array[j - 1]);
            j--;
        }
    }
}

void display(vector<int> array){
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}
