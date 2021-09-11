#include<iostream>
#include<string>
using namespace std;

int util(string &s, string &t, int m, int n, int **dp){

    if(m==-1) return n+1;
    if(n==-1) return m+1;

    if(dp[m][n] != -1) return dp[m][n];

    if(s[m]==t[n]) return util(s, t, m-1, n-1, dp);

    int replace = util(s, t, m-1, n-1, dp);
    int insert = util(s, t, m, n-1, dp);
    int remove = util(s, t, m-1, n, dp);

    dp[m][n] = 1 + min(replace, min(insert, remove));
    return dp[m][n];
}

int editDistance(string s, string t){

    int m = s.length(), n = t.length();

    int **dp = new int *[m];

    for(int i=0; i<m; i++){

        dp[i] = new int[n];

        for(int j=0; j<n; j++)
            dp[i][j] = -1;

    }

    return util(s,t, m-1, n-1, dp);
}

int main(void){

    string s= "geek";
    string t = "gesek";

    cout<<editDistance(s, t);
}