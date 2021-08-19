#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

/*

maintain 3 arrays : key(int) mst(bool) parent(int)

key: initialized with inf except src, key[src]=0
mst: intialized with false
parent: intialized with -1

step 1: get the min key that is not part of the mst, mark its mst as true

step 2: go to its adecent nodes 
        if node is not part of mst
            key[node]=edge weight
            update parent[node]

    (note: till now nodes are not marked as part of mst) 
    after visiting all adjecent nodes check they key array,
    mark mst[node]=true having min key (check if mst[node] is already true, if yes skip it) 

step 3: repeat step till every node is visited

(parent array is required to build the mst)
(sum of key array gives the total cost of spanning)

*/

// T: greater then O(n^2)

void primsBrute(vector<pair<int,int>>adj_list[], int n){

    vector<int> key(n+1, INT_MAX), parent(n+1, -1);
    vector<bool> mst(n+1, false);

    key[1]=0;
    parent[1]=-1;

    for(int count=0; count<n-1; count++){ // mst has n-1 edges

        int min=INT_MAX, u;

        for(int v=1; v<=n; v++){

            // if node has not is not in mst and has min key
            if(mst[v]==false && key[v]<min)
                min=key[v], u=v;

            // mark it in mst
            mst[u]=true;

            // go to its adjecent nodes
            for(auto it: adj_list[u]){

                int v = it.first;
                int wt = it.second;

                // if node is not in mst and edge weight is less then key
                if(mst[v]==false && wt<key[v])
                    parent[v]=u, key[v]=wt;
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout<<parent[i]<<" -> "<<endl;
}

int main(void){

    int n, m;
    vector<pair<int,int>> adj_list[n+1];

    for(int i=0; i<m; i++){

        int u,v,wt;
        cin>>u>>v>>wt;

        adj_list[u].push_back({v,wt});
        adj_list[v].push_back({u,wt});

    }

    primsBrute(adj_list, n);
}