#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool checkCycle(vector<int> adj_list[], int n){

    int counter=0;
    queue<int>q;
    vector<int> indegree(n+1, 0);

    for(int i=1; i<=n; i++){
        for(auto it: adj_list[i])
            indegree[it]++;
    }

    for(int i=1; i<=n; i++){
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){

        int node = q.front();
        q.pop();
        counter++;

        for(auto it: adj_list[node]){

            indegree[it]--;

            if(indegree[it]==0)
                q.push(it);
        }
    }


    if(counter==n) // if topo sort is not possible
        return 0;

    return 1;
}

int main(void){
}