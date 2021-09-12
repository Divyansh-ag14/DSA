#include<iostream>
using namespace std;

/* 
    nPr = n!/(n-r)!
    n!= n* n-1 * n-2 * ... n-r+1 * (n-r)!
    => nPr = n * n-1 * n-2 * ... n-r+1
*/

// T: O(n)  S(n)
int nPr(int n, int r){

    int dp[n+1];
    dp[0] = 1;

    for(int i=1; i<=n; i++)
        dp[i] = i*dp[i-1];

    return dp[n]/dp[n-r];

}

// T: O(n)   S: O(1)
int nPrOptimized(int n, int r){

    int p=1;
    for(int i=1; i<r; i++)
        p = p * (n-i);

    return p; 
    
}

int main(void){
}