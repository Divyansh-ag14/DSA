// shortest path in undirected graph

#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<queue>
using namespace std;

void dijkstra(vector<pair<int,int>> adj_list[], int n, int src){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap
    vector<int> distance(n+1, INT_MAX);

    distance[src] = 0;

    pq.push({0, src});

    while(!pq.empty()){

        int dist = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        for(auto it : adj_list[prev]){

            int next = it.first;
            int next_distance = it.second;

            if(distance[prev] + next_distance < distance[next]){
                distance[next] = distance[prev] + next_distance;
                pq.push({distance[next], next});
            }
        }
    }

    cout<<"Distance from source: "<<endl;
    for(int i=1; i<=n; i++)
        cout<<distance[i]<<" ";
}



int main(void){

    int n, m;

    cin>>n>>m;

    vector<pair<int, int>> adj_list[n+1];

    for(int i=0; i<m; i++){

        int u,v, wt;
        cin>>u>>v>>wt;

        adj_list[u].push_back({v, wt});
        adj_list[v].push_back({u, wt});

    }

    dijkstra(adj_list, n, 1);

}
