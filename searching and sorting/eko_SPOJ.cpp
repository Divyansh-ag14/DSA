#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int arr[], int n, int m, int x){

    long long int sum = 0;

    for(int i=0; i<n; i++){
        if(m < arr[i])
            sum+= arr[i] - m;
    }

    if(sum >= x) return 1;
    return 0;

}

int main(void){

    int n;
    long long int x;
    cin>>n>>x;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    long long int i = 0;
    long long int j = *max_element(arr, arr+n);


    long long int ans=0;
    while(i<=j){

        long long int  m = (i+j)/2;

        if(isFeasible(arr, n, m, x)){
            ans = m;
            i = m+1;
        }

        else j = m-1; 
    }

    cout<<ans;

}