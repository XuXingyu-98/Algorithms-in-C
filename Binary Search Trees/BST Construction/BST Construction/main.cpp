//
//  main.cpp
//  BST Construction
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
    
    BST(int val){
        value = val;
        left = NULL;
        right = NULL;
    }
    
    BST &insert(int val){
        if(val < value){
            if(left == NULL){
                BST *newBST = new BST(val);
                left = newBST;
            }else{
                left->insert(val);
            }
        }else{
            if(right == NULL){
                BST *newBST = new BST(val);
                right = newBST;
            }else{
                right->insert(val);
            }
        }
        return *this;
    }
    
    bool contains(int val){
        if(val < value){
            if(left == NULL){
                return false;
            }else{
                return left->contains(val);
            }
        }else if (val > value){
            if(right == NULL){
                return false;
            }else{
                return right->contains(val);
            }
        }else
            return true;
    }
    
    BST &remove(int val, BST *parent = NULL){
        if(val < value)
            if(left != NULL)
                left->remove(val, this);
            else if(val > value){
                if(right != NULL)
                    right->remove(val, this);
            }else{
                if(left != NULL && right != NULL){
                    value = right->getMinValue();
                    right->remove(value, this);
                }else if (parent == NULL){
                    if(left != NULL){
                        value = left->value;
                        left = left->left;
                        right = left->right;
                    }else if (right != NULL){
                        value = right->value;
                        left = right->left;
                        right = right->right;
                    }
                }else if (parent->left == this)
                    parent->left = left != NULL ? left : right;
                else if (parent->right == this)
                    parent->right = left != NULL ? left : right;
            }
        return *this;
    }
    
    int getMinValue(){
        if(left == NULL)
            return value;
        return left->getMinValue();
    }
};
