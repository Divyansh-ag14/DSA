// given an array and a sum x, find smallest subarray with sum > x


#include<iostream>
using namespace std;

int findLen(int arr[], int n, int x){

    int s=0, len=1, start=0, end=0, ans=0;

    for(end=0; end<n && s<x; end++){
        s+=arr[end];
        len++;
    }

    ans=len;
     
    while(end<n){

        s+=arr[end];
        len++;

        while(s > x && start<end){

            s-=arr[start++];
            len--;
            ans = min(ans, len);
        }

        end++;
    }

    if(ans==n+1) cout<<"no subarray is found"<<endl;
    return ans;
}

int findLen2(int arr[], int n, int k){

    int s=0, i=0, j=0, ans=n+1;

    while(j<n){

        while(j<n && s<=k)
            s+=arr[j++];

        while(s>k && i<j){

            ans = min(ans, j-i);
            s-=arr[i++];

        }

    }
    return ans;

}

int main(void){

    int arr[6]= {52, 4, 45, 6, 10, 19};

    cout<<findLen2(arr, 6, 51);
}