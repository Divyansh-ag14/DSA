#include<iostream>
using namespace std;

// time complexity without dp: O(2^n)
// time complexity with dp: O(n)

const int N = 1e5;

int dp[N];

// top down (big to small)
int fib(int n){

    if(n==0 || n==1) return 0;
    if(n==2) return 1;
    if(dp[n] != -1) return dp[n];

    dp[n] =  fib(n-1) + fib(n-2);

    return dp[n];
}

// bottom up (small to big)
int fib2(int n){

    int dp[n+1];    

    dp[0]=0, dp[1]=0, dp[2]=1;

    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
    
}

// space optimized
int fib3(int n){

// instead of creating array we can just store the prev numbers and then update them accordingly
    int a=0, b=1;

    if(n==1)
        return a;

    for(int i=3; i<=n; i++){
        b=b+a;
        a=b-a;
    }

    return b;
}

int main(void){

    int n; cin>>n;

    for(int i=0; i<N; i++)
        dp[i] = -1;

    cout<<fib2(n)<<endl;
}