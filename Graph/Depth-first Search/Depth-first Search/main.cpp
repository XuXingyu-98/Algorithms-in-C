//
//  main.cpp
//  Depth-first Search
//
//  Created by Federico Xu on 17/09/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    string name;
    vector<Node *> children;
    
    Node(string name){
        this->name = name;
    }
    
    vector<string> DFS(vector<string> *array){
        array->push_back(this->name);
        for(int i = 0; i < this->children.size(); i++)
            children[i]->DFS(array);
        
        return *array;
    }
    
    Node *addChild(string name){
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
    
};
