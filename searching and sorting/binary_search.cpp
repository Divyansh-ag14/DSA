#include<iostream>
using namespace std;
int main(void){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int k; cin>>k;
    int l=0, r=n-1;

   while(l<=r){

       int m= (l+r)/ 2;

       if(arr[m]==k){ cout<<"index: "<<m; return 1; }

       else if(arr[m]<k) l=m+1;
       
       else r=m-1;
   }

   cout<<k<<" is not in the array";
   return 0;
}   