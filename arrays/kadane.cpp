#include<iostream>
#include<algorithm>
using namespace std;

int kadane(int arr[], int n){

    int ans=INT8_MIN;
    int s=0;
    for(int i=0; i<n; i++){
        s+=arr[i];
        ans=max(ans, s);
        if(s<0) s=0;
    }

    return ans;

}

// dp soltuion
int kadane2(int arr[], int n){

    int mx=arr[0];
    int curr_sum=arr[0];

    for(int i=1; i<n; i++){

        curr_sum = max(arr[i], curr_sum+arr[i]);
        mx = max(curr_sum, mx);

    }

    return mx;

}

int main(void){
}