// Given an array arr[] of size N, check if it can be partitioned into two parts 
// such that the sum of elements in both parts is the same.

#include<iostream>
using namespace std;

int util(int arr[], int **dp, int n, int s){

    if(n==-1) return 0; // if no more elements left in the array: return 0

    if(s<0) return 0; // if sum becomes less then 0: return 0

    if(s==0) return 1; // if sum becomes: ans found
    
    if(dp[n][s] != -1) return dp[n][s]; // if dp has some value: return it

    // for every element we have 2 choices: take or leave
    // if we take the element: s becomes s-arr[n]
    // if we leave the element: s remains same
    // note n is decreased in both 
    // any choice can give the ans so use (|| operator)
    return dp[n][s] = util(arr, dp, n-1, s-arr[n]) || util(arr, dp, n-1, s);

}

// Expected Time Complexity: O(N*sum of elements)
// Expected Auxiliary Space: O(N*sum of elements)
int equalPartition(int N, int arr[]){

    int s = 0;

    for(int i=0; i<N; i++)
        s+=arr[i];

    if(s%2!=0) // if sum is odd it cant be broken into 2 parts
        return 0;

    int **dp = new int*[N];

    for(int i=0; i<N; i++){

        dp[i] = new int[s+1];

        for(int j=0; j<=s; j++)
            dp[i][j] = -1;

    }

    s = s/2;

    return util(arr, dp, N-1, s);

}

int main(void){
}