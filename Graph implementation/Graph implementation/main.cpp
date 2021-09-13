//
//  main.cpp
//  Graph implementation
//
//  Created by Federico Xu on 16/09/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node* next;
};

typedef struct {
    int src;
    int dest;
}Edge;

class Graph{
    Node* getAdjListNode(int dest, Node *head){
        Node *newNode = new Node;
        newNode->val = dest;
        newNode->next = head;
        return newNode;
    }
public:
    int V;
    Node **head;
    
    Graph(Edge edges[], int n, int N){
        head = new Node*[N];
        this->V = N;
        
        for(int i = 0; i < N; i++)
            head[i] = nullptr;
        
        for(int i = 0; i < n; i++){
            int src = edges[i].src;
            int dest = edges[i].dest;
            
            Node* newNode = getAdjListNode(dest, head[src]);
            
            head[src] = newNode;
            
            /* Uncomment below lines for undirect graph
             new Node = getAdjListNode(src, head[dest]);
             head[dest] = newNode;
             */
        }
    }
    
    ~Graph(){
        for(int i = 0; i < V; i++)
            delete[] head[i];
        
        delete[] head;
    }
};

void printList(Node* vertix){
    while(vertix != nullptr){
        cout << " -> " << vertix->val << " ";
        vertix = vertix->next;
    }
    cout << endl;
}

void DFS(Graph *G);
void dfsR(Graph *G, Edge e, int &time, int *pre, int *post, int *st);

int main(int argc, const char * argv[]) {
    
    Edge edges[] = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1},
        {3, 2}, {4, 5}, {5, 4}
    };
    
    int N = 6;
    int n = sizeof(edges)/sizeof(edges[0]);
    
    Graph *graph = new Graph(edges, n, N);
    for(int i = 0; i < N; i++){
        cout << i << " --";
        printList(graph->head[i]);
    }
    cout << endl;
    DFS(graph);
}

void DFS(Graph *G){
    int v, time = 0;
    int *pre = new int[G->V];
    int *post = new int[G->V];
    int *st = new int[G->V];
    for(v = 0; v < G->V; v++){
        pre[v] = -1;
        post[v] = -1;
        st[v] = -1;
    }
    for(v = 0; v < G->V; v++)
        if(pre[v] == -1)
            dfsR(G, {v, v}, time, pre, post, st);
    cout << "\nDiscovery/endprocessing time labels" << endl;
    for(v = 0; v < G->V; v++)
        cout << "vertix " << v << ": " << pre[v] << "/" << post[v] << endl;
    cout << "\nResulting DFS tree" << endl;
    for(v = 0; v < G->V; v++)
        printf("%d's parent: %d\n", v, st[v]);
    delete [] pre;
    delete [] post;
    delete [] st;
}

void dfsR(Graph *G, Edge e, int &time, int *pre, int *post, int *st){
    Node* t;
    int dest = e.dest;
    if(e.src != e.dest)
        printf("(%d, %d)\n", e.src, e.dest);
    st[e.dest] = e.src;
    pre[dest] = time++;
    for(t = G->head[dest]; t != nullptr; t = t->next)
        if(pre[t->val] == -1)
            dfsR(G, {dest, t->val}, time, pre, post, st);
    post[dest] = time++;
}
