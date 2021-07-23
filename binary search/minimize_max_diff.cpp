/*
    Given an array arr[] denoting heights of N towers and a positive integer K, 
    modify the height of each tower either by increasing or decreasing them by K only once. 
    After modifying, height should be a non-negative integer. 
    Find the minimum possible difference of the height of shortest and longest towers.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main(void){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k; cin>>k;

    sort(arr, arr+n);
    
    int ans= arr[n-1]-arr[0];
    int mx, mn;
    
    for(int i=1; i<n; i++){
            
        if(arr[i]>=k){
            
            // compare with border elements
            // for max (if i can be dec then i-1 can not be)
            // so inc it by k and check with n-1
            // for min - check arr[i] and arr[0]
                
            mx= max(arr[i-1]+k, arr[n-1]-k); // maximize the value we can not decrement
            mn= min(arr[i]-k, arr[0]+k); 
                
            ans= min(ans, mx-mn);

            }
            
        }

    
    cout<<ans;
}