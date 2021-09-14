/*
Given N friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.
*/

#include<iostream>
using namespace std;
int mod  = 1e9+7;

long long int util(int i, long long int dp[]){

    if(i<=2) return i;

    if(dp[i] != -1) return dp[i];

    // take a person and check its combinations
    long long int a = (((i-1)%mod) * util(i-2, dp)%mod)%mod;
    
    // leave a person
    long long int b = util(i-1, dp)%mod;

    return dp[i] = a+b;

}



int countFriendsPair(int n){

    long long int dp[n+1];
    for(int i=0; i<=n; i++)
        dp[i]=-1;

    return util(0, dp)%mod;

}

// T: O(n)  S: O(1)
int countFriendsPairings(int n) { 

    int a = 1, b= 2, c=0;
        
    if(n<=2) return n;
        
    for(long long int i=3; i<=n; i++){
        
        c = (b%mod + ((i-1)*a)%mod)%mod;
        a = b;
        b = c;
        
    }
    
    return c;
}

int main(void){
}