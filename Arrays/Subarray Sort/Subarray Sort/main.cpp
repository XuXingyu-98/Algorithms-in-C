//
//  main.cpp
//  Subarray Sort
//
//  Created by Federico Xu on 23/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> subarraySort(vector<int> array);
bool isOutOfOrder(int i, int num, vector<int> array);
void display(vector<int> result);

int main(int argc, const char * argv[]) {
    vector<int> array = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    display(subarraySort(array));
    return 0;
}

vector<int> subarraySort(vector<int> array){
    int minOutOfOrder = INT_MAX;
    int maxOutOfOrder = INT_MIN;
    for(int i = 0; i < array.size(); i++){
        int num = array[i];
        if(isOutOfOrder(i, num, array)){
            minOutOfOrder = min(minOutOfOrder, num);
            maxOutOfOrder = max(maxOutOfOrder, num);
        }
    }
    
    if(minOutOfOrder == INT_MAX)
        return vector<int>{-1, -1};
    
    int subLeft = 0;
    while(minOutOfOrder >= array[subLeft])
        subLeft++;
    
    int subRight = array.size() - 1;
    while(maxOutOfOrder <= array[subRight])
        subRight--;
    
    return vector<int>{subLeft, subRight};
}

bool isOutOfOrder(int i, int num, vector<int> array){
    if(i == 0)
        return num > array[1];
    if(i == array.size() - 1)
        return num < array[i - 1];
    
    return num < array[i - 1] || num > array[i + 1];
}

void display(vector<int> result){
    cout << result[0] << " " << result[1] << endl;
}
