//
//  main.cpp
//  Monotonic Array
//
//  Created by Federico Xu on 22/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void isMonotonic(vector<int> array);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
    isMonotonic(array);
    return 0;
}

void isMonotonic(vector<int> array){
    if(array.size() <= 2)
        cout << "The array is monotonic\n";
    int dir = 0, i = 0;
    for(i = 0; i < array.size() - 1 && !dir; i++){
        if(array[i] == array[i + 1])
            continue;
        if(array[i] < array[i + 1])
            dir = 1;
        else dir = 2;
    }
    if(dir == 0){
        cout << "The array is monotonic\n";
        return;
    }
    if(dir == 1){
        while(i < array.size() - 1){
            if(array[i] > array[i + 1]){
                cout << "The array is not monotonic\n";
                return;
            }
            i++;
        }
    }
    else{
        while(i < array.size() - 1){
            if(array[i] < array[i + 1]){
                cout << "The array is not monotonic\n";
                return;
            }
            i++;
        }
    }
    cout << "The array is monotonic\n";
}
