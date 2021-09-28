#include<bits/stdc++.h>
#include<string>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3){

    int dp[n1+1][n2+1][n3+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            for(int k=1; k<=n3; k++){

                if(A[i-1]==B[j-1] && B[j-1]==C[k-1])
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];

    	        else
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));

            }
        }
    }

    return dp[n1][n2][n3];

}

int main(void){
    

    string A = "geeks", B = "geeksfor", C = "geeksforgeeks";

    int n1 = A.length(), n2 = B.length(), n3 = C.length();

    cout<<LCSof3(A, B, C, n1, n2, n3);
}
