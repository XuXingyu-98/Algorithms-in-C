//
//  main.cpp
//  Validate BST
//
//  Created by Federico Xu on 30/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

class BST{
public:
    int value;
    BST *left;
    BST *right;
    
    BST(int val);
    BST &insert(int val);
};

bool validateBst(BST *tree);
bool validateBstHelper(BST *tree, int minValue, int maxValue);

bool validateBst(BST *tree){
    return validateBstHelper(tree, INT_MIN, INT_MAX);
}

bool validateBstHelper(BST *tree, int minValue, int maxValue){
    if(tree->value < minValue || tree->value > maxValue)
        return false;
    if(tree->left != NULL && !validateBstHelper(tree->left, minValue, tree->value))
        return false;
    if(tree->right != NULL && !validateBstHelper(tree->right, tree->value, maxValue))
        return false;
    return true;
}
