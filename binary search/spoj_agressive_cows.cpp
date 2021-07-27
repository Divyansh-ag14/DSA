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

int getDistance(int arr[], int n, int c){

    sort(arr, arr+n);

    int i=1, j = 1e9;

    int res = -1;

    while(i<j){

        int m = (i+j)/2;

        if(isFeasible(arr, n, m, c)){

            res= max(m, res);
            i= m+1;
        }

        else 
            j= m;
    }

    return res;
}

int main(void){

    int t; cin>>t;
    while(t--){

        int n,c; 
        cin>>n>>c;
        
        int arr[n];

        for(int i=0; i<n; i++) cin>>arr[i];

        cout<<getDistance(arr, n, c)<<endl;

    }
    
}