#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int arr[], int n, int m, int k){

    int count=1;
    int pos = arr[0];

    for(int i=1; i<n; i++){

        if(arr[i]-pos >= m){
            count++;
            pos=arr[i];
        }

        if(count == k)
            return 1;

    }

    return 0;
}

int getDistance(int arr[], int n, int k){

    sort(arr, arr+n);

    int i=1, j = arr[n-1];

    int res = -1;

    while(i<j){

        int m = (i+j)/2;

        if(isFeasible(arr, n, m, k)){

            res= max(m, res);
            i= m+1;
        }

        else 
            j= m;
    }

    return res;
}

int main(void){

    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    int k; cin>>k;

    cout<<getDistance(arr, n, k);
    
}