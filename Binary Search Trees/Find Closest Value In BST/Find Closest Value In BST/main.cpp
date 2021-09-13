//
//  main.cpp
//  Find Closest Value In BST
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <float.h>
using namespace std;

class BST{
public:
    int value;
    BST *left;
    BST *right;
    
    BST(int val);
    BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target);
int findClosestValueInBstHelper(BST *tree, int target, int closest);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

int findClosestValueInBst(BST *tree, int target){
    return findClosestValueInBstHelper(tree, target, tree->value);
}

int findClosestValueInBstHelper(BST *tree, int target, int closest){
    if(abs(tree->value - target) < abs(target - closest))
        closest = tree->value;
    if(target < tree->value && tree->left != NULL)
        return findClosestValueInBstHelper(tree->left, target, closest);
    else if(target > tree->value && tree->right != NULL)
        return findClosestValueInBstHelper(tree->right, target, closest);
    else
        return closest;
}
