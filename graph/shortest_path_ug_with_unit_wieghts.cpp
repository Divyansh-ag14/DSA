#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;


void BFS(vector<int> adj_list[], int n, int src){

    vector<int> distance(n+1, 0);
    queue<int> q;

    for(int i=1; i<=n; i++)
        distance[i] = INT_MAX;

    distance[src] = 0;

    q.push(src);

    while(!q.empty()){

        int node = q.front();
        q.pop();

        for(auto it: adj_list[node]){
            
            if(distance[node]+1 < distance[it])
                distance[it] = distance[node]+1;
                q.push(it);
        }
    }

    for(int i=1; i<=n; i++)
        cout<<distance[i]<<" ";
}

int main(void){
}