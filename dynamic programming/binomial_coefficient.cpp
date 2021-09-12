#include<iostream>
using namespace std;

/*
    nCr = n!/r!(n-r)! 
    nCr = nC(n-r)

    factorial till nCn
    0! = 1 
    1! = 1 1
    2! = 1 2 1  (pascals tri: no = sum of prev 2 from above)
    3! = 1 3 3 1 
    4! = 1 4 6 4 1 

*/

int nCr(int n, int r){

    int mod = 1e9+7;
    if(n<r) return 0;   

    if((n-r) < r) r = n-r; // compute for smaller value: both will give same ans

    int dp[r+1]; // r+1 to store to get the index as number

    for(int i=0; i<=r; i++) dp[i] = 0;
    dp[0]=1;

    for(int i=1; i<=n; i++){ // pasacl tri

        for(int j=min(i,r); j>0; j--)       // min (i,r): suppose we want to find 4C2
            dp[j] = (dp[j] + dp[j-1])%mod;  // at a point when i becomes 4 we only want to run loop from 2 to get 4C2

    }

    return dp[r];
}

int main(void){
}