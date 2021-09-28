#include<bits/stdc++.h>
using namespace std;

int dp[21][21][21];

int util(string A, string B, string C, int n1, int n2, int n3){

    if(n1==-1 ||n2==-1 || n3==-1)
        return 0;

    if(A[n1]==B[n2] && B[n2]==C[n3]) return 1 + util(A, B, C, n1-1, n2-1, n3-1);

    if(dp[n1][n2][n3] != -1) return dp[n1][n2][n3];

    int opt1 = util(A, B, C, n1-1, n2, n3);
    int opt2 = util(A, B, C, n1, n2-1, n3);
    int opt3 = util(A, B, C, n1, n2, n3-1);

    return dp[n1][n2][n3] = max(opt1, max(opt1, opt2));

}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3){
    
    memset(dp, -1, sizeof(dp));
    
    return util(A,B,C, n1-1, n2-1, n3-1);
    
}

int main(void){

    string A = "geeks", B = "geeksfor", C = "geeksforgeeks";

    int n1 = A.length(), n2 = B.length(), n3 = C.length();

    cout<<LCSof3(A, B, C, n1, n2, n3);
}