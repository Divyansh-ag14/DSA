#include<iostream>
#include<vector>
using namespace std;

bool checkBipartite(vector<int> adj_list[], vector<int> &color, int i){

    if(color[i] == -1)
        color[i] = 0;

    for(auto it: adj_list[i]){

        if(color[it] == -1){
            color[it] = 1 - color[i];
            if(!checkBipartite(adj_list, color, it))
                return 0;
        }

        else if(color[it] == color[i])
            return 0;
    }

    return 1;

}

bool isBipartite(vector<int> adj_list[], int n){

    vector<int> color(n+1, -1);

    for(int i=1; i<=n; i++){

        if(color[i] == -1){

            if(!checkBipartite(adj_list, color, i))
                return 0;
        }        
    }

    return 1;

}

int main(void){


    int n, m;
    cin>>n>>m;

    vector<int> adj_list[n+1];

    for(int i=0; i<m; i++){

        int u, v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    cout<<isBipartite(adj_list, n);

}