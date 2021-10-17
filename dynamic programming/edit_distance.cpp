/*

Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. 
The possible operations are:

Insert
Remove
Replace

*/
#include<iostream>
#include<string>
using namespace std;

int util(string &s, string &t, int m, int n, int **dp){

    if(m==-1) return n+1; // if one string is over return the index of another (+1 for 0 based indexing)
    if(n==-1) return m+1;

    if(dp[m][n] != -1) return dp[m][n]; // if dp array already has some value: return it

    if(s[m]==t[n]) return util(s, t, m-1, n-1, dp); // if both the chars are same: dec index of both strings

    // if chars are diff
    int replace = util(s, t, m-1, n-1, dp); // if a char is replaced it becomes equal to the char in other, now simply move by dec m and n
    int insert = util(s, t, m, n-1, dp); // if an char is added after index(m) of 1st string: dec sec str and check with 1st str i
    int remove = util(s, t, m-1, n, dp); // if a char is removed from 1st str: simply dec its index

    dp[m][n] = 1 + min(replace, min(insert, remove));
    return dp[m][n];
}

int editDistance(string s, string t){

    int m = s.length(), n = t.length();

    int **dp = new int *[m]; // 2d dp array 

    for(int i=0; i<m; i++){

        dp[i] = new int[n];

        for(int j=0; j<n; j++)
            dp[i][j] = -1; // intially filled with -1

    }

    return util(s,t, m-1, n-1, dp);
}

int main(void){

    string s= "geek";
    string t = "gesek";

    cout<<editDistance(s, t);
    
}