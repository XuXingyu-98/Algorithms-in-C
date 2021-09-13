//
//  main.cpp
//  Graph STL
//
//  Created by Federico Xu on 17/09/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int src, dest;
};

class Graph{
public:
    vector<vector<int>> G;
    int V;
    
    Graph(vector<Edge> const &edges, int N){
        G.resize(N);
        V = N;
        for(auto &edge: edges){
            G[edge.src].push_back(edge.dest);
            /*
             uncomment below line for undirected graph
             adjList[edge.dest].push_back(edge.src);
             */
        }
    }
};

void printGraph(Graph const &graph, int N){
    for(int i = 0; i < N; i++){
        cout << i << " --> ";
        
        for(int v: graph.G[i])
            cout << v << " ";
        cout << endl;
    }
}

void DFS(Graph const &graph);
void dfsR(Graph const &graph, Edge e, int &time, vector<int> &pre, vector<int> &post, vector<int> &st);

int main(int argc, const char * argv[]) {
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1},
        {3, 2}, {4, 5}, {5, 4}
    };
    
    int N = 6;
    Graph graph(edges, N);
    printGraph(graph, N);
    DFS(graph);
    return 0;
}

void DFS(Graph const &graph){
    int time = 0, v = 0;
    vector<int> pre(graph.V, -1);
    vector<int> post(graph.V, -1);
    vector<int> st(graph.V, -1);
    for(v = 0; v < graph.V; v++)
        if(pre[v] == -1)
            dfsR(graph, {v, v}, time, pre, post, st);
    cout << "\nDiscovery/endprocessing time labels" << endl;
    for(v = 0; v < graph.V; v++)
        cout << "vertix " << v << ": " << pre[v] << "/" << post[v] << endl;
    cout << "\nResulting DFS tree" << endl;
    for(v = 0; v < graph.V; v++)
        printf("%d's parent: %d\n", v, st[v]);
}

void dfsR(Graph const &graph, Edge e, int &time, vector<int> &pre, vector<int> &post, vector<int> &st){
    int dest = e.dest;
    if(e.src != e.dest)
        printf("(%d, %d)\n", e.src, e.dest);
    st[e.dest] = e.src;
    pre[dest] = time++;
    for(int i = 0; i < graph.G[dest].size(); i++)
        if(pre[graph.G[dest][i]] == -1)
            dfsR(graph, {dest, graph.G[dest][i]}, time, pre, post, st);
    post[dest] = time++;
}
