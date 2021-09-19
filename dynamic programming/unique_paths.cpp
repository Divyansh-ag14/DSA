/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

#include<iostream>
using namespace std;

int uniquePaths(int m, int n){

    int dp[m+1][n+1];

    // first row and col will contain 1 (as there is only 1 way to reach them)
    for(int i=1; i<=m; i++) dp[i][1] = 1;
    for(int i=1; i<=n; i++) dp[1][i] = 1;

    for(int i=2; i<=m; i++){

        for(int j=2; j<=n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }

    return dp[m][n];

}

int main(void){

    cout<<uniquePaths(3, 3);
}