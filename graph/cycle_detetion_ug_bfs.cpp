#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

bool checkCycle(vector<int> adj_list[], vector<int>&visited, int i, int n){

    visited[i]=1;
    
    queue<pair<int,int>>q; // queue for bfs
    q.push({i, -1}); // parent of first node is -1

    while(!q.empty()){

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it: adj_list[node]){

            if(!visited[it]){
                visited[it]=1;
                q.push({it, node});
            }

            else if (parent != it) // if an element has been visited before and is not the parent of current node - (cycle)
                return 1;
        }

    }

    return 0;
}

bool isCycle(vector<int> adj_list[], int n){

    vector<int> visited(n+1, 0);

    for(int i=1; i<=n; i++){ // check for cycle in every component

        if(!visited[i]){
            if (checkCycle(adj_list, visited, i, n))
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