/*
    1. create a min heap of pairs
    
    2. insert {first, element, array number} of all the sorted arrays into minheap
    
    3. pop the first element from minheap and store it in the ans arr,
       insert the the next element of same array number into the min heap.
       (to get the same array, we have made pairs containing array number)

    4. (keep track of indices using an index array)

*/

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int k=0;

void merge(vector<int>varr[]){

    // idx vector of size k initially filled with 0s
    vector<int> idx(k, 0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    // push first element of every array into heap 
    for(int i=0; i<k; i++)
        pq.push({varr[i][0], i});

    vector<int>ans;

    while(!pq.empty()){

        pair<int, int> x= pq.top(); 
        pq.pop();
        ans.push_back(x.first);

        // if curr index of arr is less then its size then push its next element in pq
        if(idx[x.second]+1 < varr[x.second].size()){
            
            pq.push({varr[x.second][idx[x.second]+1], x.second});
            idx[x.second]+=1;

        }
    }

     for(auto i: ans)
        cout<<i<<" ";

}

int main(void){

    cin>>k; // no of arrays

    vector<int> varr[k]; // array of vectors

    for(int i=0; i<k; i++){ // for every vector in arr

        int size; // get its size
        cin>>size; // size of arrays

        for(int j=0; j<size; j++){ //input elements in it
            
            int x; cin>>x;
            varr[i].push_back(x);
        }

    }
    
    merge(varr);

}
