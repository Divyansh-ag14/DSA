#include<iostream>
#include<vector>
using namespace std;

void DFS_util(int node, vector<int> adj_list[], vector<int> &visited, vector<int> &dfs){

    dfs.push_back(node);

    visited[node]=1;

    for(auto it: adj_list[node]){

        if(!visited[it])
            DFS_util(it, adj_list, visited, dfs);
    }

}

vector<int> DFS(vector<int> adj_list[], int n){

    vector<int>visited(n+1, 0);
    vector<int>dfs;

    for(int i=1; i<=n; i++){

        if(!visited[i])
            DFS_util(i, adj_list, visited, dfs);

    }

}

int main(void){
}