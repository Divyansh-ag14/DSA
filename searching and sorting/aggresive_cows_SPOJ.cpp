#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int arr[], int n, int m, int c){

    int cows=1;
    int pos = arr[0];

    for(int i=1; i<n; i++){

        if(arr[i]-pos >= m){

            cows++;
            pos=arr[i];
        
        }

        if(cows == c)
            return 1;

    }

    return 0;
}


int main(void){

    int t; cin>>t;
    while(t--){

        int n,c; 
        cin>>n>>c;
        
        int arr[n];

        for(int i=0; i<n; i++) cin>>arr[i];

        sort(arr, arr+n);

        int i=1, j = 1e9;

        int ans =0;

        while(i<j){

            int m = (i+j)/2;

            if(isFeasible(arr, n, m, c)){

                ans= m;
                i= m+1;
        
            }

            else 
                j= m;

        }

        cout<<ans<<endl;

    }
    
}