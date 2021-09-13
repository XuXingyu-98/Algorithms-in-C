//
//  main.cpp
//  Weighted Directed Graph implementation
//
//  Created by Federico Xu on 17/09/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int val, cost;
    Node* next;
};

struct Edge{
    int src, dest, weight;
};

class Graph{
    Node* getAdjListNode(int value, int weight, Node* head){
        Node* newNode = new Node;
        newNode->val = value;
        newNode->next = head;
        newNode->cost = weight;
        return newNode;
    }
    
    int N;
public:
    Node **head;
    
    Graph(Edge edges[], int n, int N){
        head = new Node*[N]();
        this->N = N;
        
        for(int i = 0; i < N; i++)
            head[i] = nullptr;
        
        for(int i = 0; i < n; i++){
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;
            
            Node* newNode = getAdjListNode(dest, weight, head[src]);
            
            head[src] = newNode;
        }
    }
    
    ~Graph(){
        for(int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }
};

void printList(Node* ptr, int i){
    while(ptr != nullptr){
        cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Edge edges[] = {
        {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4},
        {3, 2, 10}, {4, 5, 1}, {5, 4, 3}
    };
    int N = 6;
    int n = sizeof(edges)/sizeof(edges[0]);
    Graph graph(edges, n, N);
    
    for(int i = 0; i < N; i++)
        printList(graph.head[i], i);
    return 0;
}
