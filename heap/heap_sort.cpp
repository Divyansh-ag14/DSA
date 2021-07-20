/* take input
   maxheapify - start from the 2nd last level
   swap root with last element
   maxheapify again with size-1 (as last element is in place)
*/

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void heapify(vector<int>&v, int i, int n){

        int l= (2*i)+1;
        int r= (2*i)+2;
        int largest=i;

        if(l<n && v[l]>v[largest])
            largest=l;
        
        if(r<n && v[r]>v[largest])
            largest=r;

        if(largest!=i){
            swap(v[i], v[largest]);
            heapify(v, largest, n);
        }

}

void heapSort(vector<int>&v){
    
    int n= v.size();
    
    if(n<=0) return;

    for(int i=n/2-1; i>=0; i--) // this loop starts from the n-1th level 
        heapify(v,i, n);

    // swap first and last elments
    for(int i=n-1; i>=0; i--){
        swap(v[0], v[i]);
        heapify(v, 0, i);
    }
    
}

//  T: O(n log n)
int main(void){

    int n; cin>>n;
    vector<int>v;
    for(int i=n; i>=1; i--) v.push_back(i);
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
    heapSort(v);

    for(auto i: v) cout<<i<<" ";
}