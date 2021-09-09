/*
Given a value N, find the number of ways to make change for N cents, 
if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.
*/

#include<iostream>
using namespace std;

long long int countUtil(int arr[], long long int **dp, int m, int n){

    if(m==-1 && n>0) // if theere are no more elements ans the sum is still not 0: return 0
        return 0;

    if(n==0) return 1; // if the sum becomes 0: return 1

    if(n<0) return 0; // if sum becomes less then 0: return 0

    if(dp[m][n] != -1) return dp[m][n]; // if a value is present at curr loc: return it

    // at every step: we have a choice to include the coin or not
    // if included: size remains same(m), sum becomes n-arr[m]
    // if not included: size decreases by 1(m-1), sum remains same(n)
    dp[m][n] = countUtil(arr, dp, m, n-arr[m]) + countUtil(arr, dp, m-1, n);

    return dp[m][n];

}

long long int count(int arr[], int m, int n){

    // create 2d dp array
    long long int **dp = new long long int *[m]; // rows equal to the number of coins

    for(int i=0; i<m; i++){
        dp[i] = new long long int[n+1]; // cols equal to n+1 (to include entire sum value)
        for(int j=0; j<=n; j++){
            dp[i][j] = -1; // fill it with -1
        }
    }

    // traverse array from back: so we just need to check when index becomes negative
    return countUtil(arr, dp, m-1, n);
}

int main(void){

    int n=10, m=4;
    int arr[] = {2,5,3,6};

    cout<<count(arr, m, n);
}