#include<iostream>
#include<vector>
#include<utility>
using namespace std;

bool checkCycle(vector<int> adj_list[], vector<int> &visited, int i, int parent){

    visited[i]=1; // mark the current node as visited

    for(auto it: adj_list[i]){ // go to its adjecent node

        if(!visited[it]){ // if it is not visited call function again
            if (checkCycle(adj_list, visited, it, i));
                return 1;
        }

        else if(it != parent) return 1;   // else if the node has been visited and is not the parent - (cycle)
    }

    return 0;
}

bool isCycle(vector<int> adj_list[], int n){

    vector<int>visited(n+1, 0);

    for(int i=1; i<=n; i++){ // for loop to handle disconnected components

        if(!visited[i]){ 
            if(checkCycle(adj_list, visited, i, -1)) // parent of first node is -1
                return 1;
        }
    }

    return 0;

}

int main(void){

    int n, m;

    vector<int> adj_list[n+1];

    for(int i=0; i<m; i++){

        int u, v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    cout<<isCycle(adj_list, n);

}