#include<iostream>
#include<vector>
using namespace std;

int main(void){

    int n,m;
    cout<<"Enter the number of nodes and edges: "; cin>>n>>m;

    // adjecent matrix: S- O(n^2)
    int adj[n+1][n+1]; // to tackle 1 based indexing declare size as n+1

    // take edges as input
    for(int i=0; i<m; i++){

        int u, v;
        cin>>u>>v;
        adj[u][v] = 1; // undireted graph
        adj[v][u] = 1;
    }

    // adjecent list: S- O(n+2e) 
    // for large number of nodes adjecent list is used as array size is limited

    vector<int> adj_list[n+1];

    for(int i=0; i<m; i++){

        int u, v;
        cin>>u>>v;

        adj_list[u].push_back(v); // undirected graph
        adj_list[v].push_back(u);

        // if graph is weighted
        // adj_list[u].push_back({v, wt});
        // adj_list[v].push_back({u, wt});

    }
}