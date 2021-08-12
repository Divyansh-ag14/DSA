#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSort(vector<int> adj_list[], int n){

    vector<int> ans;
    vector<int> indegree(n+1, 0);
    queue<int> q;

    // calculate indegree of every node
    for(int i=1; i<=n; i++){

        for(auto it: adj_list[i])
            indegree[it]++;

    }

    // push the elements who do not have indegree meaning for an edge u->v (u always appears first)
    for(int i=1; i<=n; i++){
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto it: adj_list[node]){

            indegree[it]--; // remove the edge

            if(indegree[it]==0) // if indegree becomes 0 - then there is no edge where they appear second
                q.push(it);
        }

    }

    return ans;
}

int main(void){
}