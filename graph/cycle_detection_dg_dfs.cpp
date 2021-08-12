// cycle detection in directed graph
// maitain an extra array to keep track of recursion calls

#include<iostream>
#include<vector>
using namespace std;

bool checkCycle(vector<int> adj_list[], vector<int>&visited, vector<int> &visited_dfs, int i){

    visited[i] = 1;
    visited_dfs[i] = 1;

    for(auto it: adj_list[i]){

        if(!visited[it]){
            if(checkCycle(adj_list, visited, visited_dfs, it))
                return 1;
        }

        else if(visited_dfs[it]) // if the recusrsion call for a node is not over and we reach it again - return true
            return 1;
    }

    visited_dfs[i] = 0;
    return 0;

}

bool isCycle(vector<int> adj_list[], int n){

    vector<int> visited(n+1, 0);
    vector<int> visited_dfs(n+1, 0); // this is used to know that we have made a recurrsion call for a node

    for(int i=1; i<=n; i++){

        if(!visited[i]){
            if(checkCycle(adj_list, visited, visited_dfs, i))
                return 1;
        }
    }

    return 0;
}

int main(void){
}