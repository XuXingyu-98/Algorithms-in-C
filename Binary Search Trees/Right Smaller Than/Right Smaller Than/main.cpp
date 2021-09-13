//
//  main.cpp
//  Right Smaller Than
//
//  Created by Federico Xu on 30/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class specialBST{
public:
    int value;
    int idx;
    int numSmallerAtInsertTime;
    int leftSubtreeSize;
    specialBST *left;
    specialBST *right;
    
    specialBST(int value, int idx, int numSmallerAtInsertTime){
        this->value = value;
        this->idx = idx;
        this->numSmallerAtInsertTime = numSmallerAtInsertTime;
        leftSubtreeSize = 0;
        left = NULL;
        right = NULL;
    }
    
    void insert(int value, int idx, int numSmallerAtInsertTime = 0){
        if(value < this->value){
            leftSubtreeSize++;
            if(left == NULL)
                left = new specialBST(value, idx, numSmallerAtInsertTime);
            else
                left->insert(value, idx, numSmallerAtInsertTime);
        }else{
            numSmallerAtInsertTime += leftSubtreeSize;
            if(value > this->value)
                numSmallerAtInsertTime++;
            if(right == NULL)
                right = new specialBST(value, idx, numSmallerAtInsertTime);
            else
                right->insert(value, idx, numSmallerAtInsertTime);
        }
    }
};

void getRightSmallerCounts(specialBST *bst, vector<int> &rightSmallerCounts);

vector<int> rightSmallerCounts(vector<int> array){
    if(array.size() == 0)
        return {};
    
    int lastIdx = array.size() - 1;
    specialBST *bst = new specialBST(array[lastIdx], lastIdx, 0);
    for(int i = array.size() - 2; i >= 0; i--)
        bst->insert(array[i], i);
    
    vector<int> rightSmallerCounts = array;
    getRightSmallerCounts(bst, rightSmallerCounts);
    return rightSmallerCounts;
}

void getRightSmallerCounts(specialBST *bst, vector<int> &rightSmallerCounts){
    if(bst == NULL)
        return;
    
    rightSmallerCounts[bst->idx] = bst->numSmallerAtInsertTime;
    getRightSmallerCounts(bst->left, rightSmallerCounts);
    getRightSmallerCounts(bst->right, rightSmallerCounts);
}
