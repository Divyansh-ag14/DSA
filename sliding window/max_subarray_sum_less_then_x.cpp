/* find max sum > x for a subarray of size k */


#include<iostream>
using namespace std;

int maxSum(int arr[], int n, int k, int x){

     int i=0, s=0, ans=0;

    for(i=0; i<k; i++) // 1st window
        s+=arr[i];

    if(s<x) ans=s;

    for(int j=i, i=0; j<n; j++){

        s-=arr[i];
        s+=arr[j];

        if(s<x)
            ans = max(s, ans);
    }

    return ans;
}


int main(void){

    int n; cin>>n; 
    
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    int k; cout<<"Enter length k: "; cin>>k;
    int x; cout<<"Enter sum: "; cin>>x;

    cout<<"Max sum of subarray less then "<<x<<" is: ("<<maxSum(arr, n, k, x)<<")";
}