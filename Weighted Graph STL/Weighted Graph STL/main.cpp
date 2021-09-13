//
//  main.cpp
//  Weighted Graph STL
//
//  Created by Federico Xu on 17/09/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int src, dest, weight;
};

typedef pair<int, int> Pair;

class Graph{
public:
    vector<vector<Pair>> adjList;
    
    Graph(vector<Edge> const &edges, int N){
        adjList.resize(N);
        
        for(auto &edge: edges){
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
            
            adjList[src].push_back(make_pair(dest, weight));
        }
    }
};

void printGraph(Graph const &graph, int N){
    for(int i = 0; i < N; i++){
        for(Pair v: graph.adjList[i])
            cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<Edge> edges = {
        {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4},
        {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
    };
    
    int N = 6;
    Graph graph(edges, N);
    printGraph(graph, N);
    return 0;
}
