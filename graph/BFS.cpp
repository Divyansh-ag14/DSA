#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> BFS(vector<int>adj_list[], int n){

    vector<int> bfs;
    vector<int> visited(n+1, 0); // intitially no node is marked visited

    for(int i=1; i<=n; i++){ // always use for loop as graph can have multiple (disconnected) components

        if(!visited[i]){

            queue<int>q;
            q.push(i);
            visited[i]=1; // mark the current node as visited

            while(!q.empty()){

                int node = q.front();
                bfs.push_back(node); // store the current node in ans
                q.pop();

                for(auto it: adj_list[i]){ // go to its adjecent nodes
                    q.push(it);
                    visited[it]=1;
                }
            }

        }
    }

    return bfs;
}

int main(void){
}