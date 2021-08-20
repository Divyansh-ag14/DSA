#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<limits.h>
using namespace std;

// use priority queue to find min key in O(logn)
void primsOptimized(vector<pair<int,int>>adj_list[], int n){

    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> mst(n, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[0]=0;
    parent[0]=-1;

    // only one node has key as 0
    pq.push({0,0}); // push {key, node}

    while(!pq.empty()){

        // get the node with min key
        int u = pq.top().second;
        pq.pop();

        // mark it in mst
        mst[u] = true;

        // go to its adjecent nodes
        for(auto it: adj_list[u]){
            
            int v = it.first;
            int wt = it.second;

            // if node is not in mst and wt is less then its key
            if(mst[v]==false && wt<key[v]){
                parent[v]=u, key[v]=wt;
                pq.push({key[v], v});
            }

        }

    }

    for(int i=1; i<n; i++){
        cout<<parent[i]<<" -> "<<i<<endl;
    }

}

int main(void){

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> adj_list[n];

    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj_list[u].push_back({v,wt});
        adj_list[v].push_back({u,wt});
    }

    primsOptimized(adj_list, n);

    /*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/

}