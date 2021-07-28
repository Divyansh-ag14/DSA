// Given n number of files, find the minimum computations done to reach Optimal Merge Pattern.

#include<iostream>
#include<queue>
using namespace std;

void computations(int arr[], int n){

    priority_queue<int, vector<int>, greater<int>>pq;

    for(int i=0; i<n; i++)
        pq.push(arr[i]);

    int min_comps = 0; // computations

    while(pq.size() > 1){

        int first_file = pq.top();
        pq.pop();
        int second_file = pq.top();
        pq.pop();

        int merged_file = first_file+second_file;
        min_comps += merged_file;

        pq.push(merged_file);


    }

    cout<<min_comps;  
}

int main(void){

    int n; cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    computations(arr, n);


}