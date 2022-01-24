#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

void heapify(vector<int>&v, int i, int n){

    int largest= i;
    int l= 2*i+1;
    int r= 2*i+2;

    if(l<n && v[l]>v[largest])
        largest=l;
    
    if(r<n && v[r]>v[largest])
        largest=r;

    if(largest!=i){
        swap(v[i], v[largest]);
        heapify(v, largest, i);
    }
}

void heapSort(vector<int>&v){

    int n= v.size();
    
    for(int i=n/2-1; i>=0; i--){
        heapify(v, i, n);
    }

    for(int i=n-1; i>=0; i--){
        swap(v[0], v[i]);
        heapify(v, 0, i);
    }
}

int main(void){

    int n; cin>>n;
    vector<int>v;
    for(int i=n; i>=1; i--) v.push_back(i);
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
    heapSort(v);

    for(auto i: v) cout<<i<<" ";
}