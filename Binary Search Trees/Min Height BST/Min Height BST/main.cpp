//
//  main.cpp
//  Min Height BST
//
//  Created by Federico Xu on 30/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class BST{
public:
    int value;
    BST *left;
    BST *right;
    
    BST(int value){
        this->value = value;
        left = NULL;
        right = NULL;
    }
    
    void insert(int value){
        if(value < this->value){
            if(left == NULL)
                left = new BST(value);
            else
                left->insert(value);
        }else{
            if(right == NULL)
                right = new BST(value);
            else
                right->insert(value);
        }
    }
};

BST *constructMinHeightBst(vector<int> array, int startIdx, int endIdx);

BST *minHeightBst(vector<int> array){
    return constructMinHeightBst(array, 0, array.size() - 1);
}

BST *constructMinHeightBst(vector<int> array, int startIdx, int endIdx){
    if(endIdx < startIdx)
        return NULL;
    int middle = (startIdx + endIdx) / 2;
    BST *bst = new BST(array[middle]);
    bst->left = constructMinHeightBst(array, startIdx, middle - 1);
    bst->right = constructMinHeightBst(array, middle + 1, endIdx);
    return bst;
}
