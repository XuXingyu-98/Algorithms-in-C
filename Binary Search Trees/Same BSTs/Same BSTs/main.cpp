//
//  main.cpp
//  Same BSTs
//
//  Created by Federico Xu on 30/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> getSmaller(vector<int>);
vector<int> getBiggerOrEqual(vector<int> array);

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo){
    if(arrayOne.size() != arrayTwo.size())
        return false;
    if(arrayOne[0] != arrayTwo[0])
        return false;
    if(arrayOne.size() == 0 && arrayTwo.size() == 0)
        return true;
    
    vector<int> leftOne = getSmaller(arrayOne);
    vector<int> leftTwo = getSmaller(arrayTwo);
    vector<int> rightOne = getBiggerOrEqual(arrayOne);
    vector<int> rightTwo = getBiggerOrEqual(arrayTwo);
    
    return sameBsts(leftOne, leftTwo) && sameBsts(rightOne, rightTwo);
}

vector<int> getSmaller(vector<int> array){
    vector<int> smaller;
    for(int i = 1; i < array.size(); i++)
        if(array[i] < array[0])
            smaller.push_back(array[i]);
    return smaller;
}

vector<int> getBiggerOrEqual(vector<int> array){
    vector<int> biggerOrEqual;
    for(int i = 1; i < array.size(); i++)
        if(array[i] >= array[0])
            biggerOrEqual.push_back(array[i]);
    return biggerOrEqual;
}
