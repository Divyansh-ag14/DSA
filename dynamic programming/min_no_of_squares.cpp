// find min no of squares required to generate the number

#include<iostream>
using namespace std;

const int N=1e5, mx=1e9;

int dp[N];

// top down
int minSquares(int n){

    if(n==0 || n==1 || n==2 || n==4)
        return n;

    if(dp[n] != mx)
        return dp[n];

    for(int i=1; i*i<=n; i++)
        dp[n] = min(dp[n], 1 + minSquares(n-i*i));

    return dp[n];
}

// bottom up
int minSquares2(int n){

    int dp[n+1];
    for(int i=0; i<=n; i++)
        dp[i] = mx;

    for(int i=0; i<=3; i++)
        dp[i] = i;

    for(int i=1; i*i<=n; i++){

        for(int j=0; i*i+j<=n; j++)
            dp[i*i+j] = min(dp[j]+1, dp[i*i+j]);
    
    }

    return dp[n];

}


int main(void){

    for(int i=0; i<N; i++)
        dp[i] = mx;

    cout<<minSquares2(2048);
}