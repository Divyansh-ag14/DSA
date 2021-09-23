/*

Given two sequences, find the length of longest subsequence present in both of them.

Example:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR

Output: 3

Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.

*/

#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int util(int m, int n, string &s1, string &s2){

    // if any of the string gets over: return 0
    if(m==-1 || n==-1) return 0;

    // if both the strings have same chars: add 1 and check the rest of the strings 
    if(s1[m] == s2[n]) return 1 + util(m-1, n-1, s1, s2);

    // if dp array already has some value: return it
    if(dp[m][n] != -1) return dp[m][n];

    // at every step we have 2 options
    int opt1 = util(m-1, n, s1, s2); // try to find a character of s2 in s1 (iterate s1 keeping pointer of s2 fixed)
    int opt2 = util(m, n-1, s1, s2); // try to find a character of s1 in s2 (iterate s2 keeping pointer of s1 fixed)

    // store and return the max length
    return dp[m][n] = max(opt1, opt2); 

}

int lcs(int x, int y, string s1, string s2){

    // fill dp array with -1 (as length cant be negative so it means currently we have not found ans)
    memset(dp, -1, sizeof(dp));

    // x-1 and y-1 as the last index is len-1
    return util(x-1, y-1, s1, s2);

}

int main(void){

    int A = 6, B = 6;
    string str1 = "ABCDGH", str2 = "AEDFHR";

    cout<<lcs(A, B, str1, str2);

}