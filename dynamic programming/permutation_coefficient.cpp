#include<iostream>
using namespace std;

// T: O(n)  S(n)
int nPr(int n, int r){

    int dp[n+1];
    dp[0] = 1;

    for(int i=1; i<=n; i++)
        dp[i] = i*dp[i-1];

    return dp[n]/dp[n-r];

}

int main(void){
}