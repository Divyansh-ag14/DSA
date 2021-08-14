// DAG: directed acyclic graph
// find toposort and then compare for min distance

#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#include<limits.h>
using namespace std;

void topoSort(vector<pair<int,int>>adj_list[], vector<int> visited, stack<int>s, int i){

    visited[i]=1;

    for(auto it: adj_list[i]){
        if(!visited[it.first])
            topoSort(adj_list, visited, s, it.first);
    }
    
    s.push(i);
}

void shortestPath(vector<pair<int,int>>adj_list[], int n, int src){

    vector<int> visited(n+1, 0);
    stack<int> s;
    vector<int> distance(n+1, INT_MAX);

    for(int i=1; i<=n; i++){
        if(!visited[i])
            topoSort(adj_list, visited, s, i);
    }

    distance[src] = 0;

    while(!s.empty()){

        int node = s.top();
        s.pop();

        if(distance[node] != INT_MAX){
            for(auto it: adj_list[node]){

                if(distance[node] + it.second < distance[it.first])
                    distance[it.first] = distance[node] + it.second;

            }
        }
    }

    for(int i=1; i<n; i++){

        distance[i] == INT_MAX ? cout<<"INF" : cout<<distance[i];
    }

}

int main(void){

    int n, m;
    cin>>n>>m;

    vector<pair<int,int>> adj_list[n+1];

    for(int i=0; i<m; i++){

        int u,v,wt;
        cin>>u>>v>>wt;

        adj_list[u].push_back({v, wt});
    
    }

    shortestPath(adj_list, n, 1);
}