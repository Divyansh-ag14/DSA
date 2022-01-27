#include<iostream>
#include<algorithm>
using namespace std;

int kadane(int arr[], int n){

    int mx=arr[0];
    int curr_sum=arr[0];

    for(int i=1; i<n; i++){

        curr_sum = max(arr[i], curr_sum+arr[i]);
        mx = max(curr_sum, mx);

    }
}

int main(void){
}