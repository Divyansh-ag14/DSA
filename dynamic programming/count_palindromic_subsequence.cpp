#include<iostream>
#include<string>
using namespace std;

long long int util(int i, int j, string s, long long int **dp){

    if(i>j) return 0;
    if(i==j) return 1; // single alphabet

    if(dp[i][j] != -1) return dp[i][j];

    // if the i and j match: add 1 to ans
    // search the string by increasing i and another time by decreasing j
    if(s[i]==s[j]) 
        dp[i][j] = (util(i+1,j,s, dp)%mod + util(i,j-1,s, dp)%mod + 1+mod)%mod;

    // if they dont match:
    // search the string by increasing i and another time by decreasing j
    // also subtract the common part
    // ex: abc -> bc    ab 
    //           c  b  b  a
    // b comes twice so subtract it once
    else dp[i][j] = (util(i+1,j,s, dp)%mod + util(i,j-1,s, dp)%mod - util(i+1,j-1,s, dp)%mod+mod)%mod;

    return dp[i][j]; 
}

long long int countPS(string s){

    int n = s.length();
    long long int **dp = new long long int*[n];

    for(int i=0; i<n; i++){

        dp[i] = new long long int[n];

        for(int j=0; j<n; j++)
            dp[i][j] = -1;
    }

    return util(0, n-1, s, dp);

}

int main(void){

    string s= "abca";
    cout<<countPS(s);
}