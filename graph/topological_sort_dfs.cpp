// topological sort: linear indexing of vertices, such that if there is an edge u->v, u appears before v in that indexing
// topoligical sort is only for dag graphs (direceted acylic graphs)

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void findTopoSort(vector<int> adj_list[], vector<int>&visited, stack<int>&s, int i){

    visited[i] = 1;

    for(auto it: adj_list[i]){

        if(!visited[it])
            findTopoSort(adj_list, visited, s, it);
    }

    s.push(i); // push the node whose recusrion call gets over first

}

 vector<int> topoSort(vector<int> adj_list[], int n){

     vector<int> visited(n+1, 0);
     stack<int> s;
     
     for(int i=1; i<=n; i++){

         if(!visited[i])
            findTopoSort(adj_list, visited, s, i);
     }
 }

int main(void){
}