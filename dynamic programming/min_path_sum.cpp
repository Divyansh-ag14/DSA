#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid){

    int rows = grid.size();
    int cols = grid.size();

    // create a dp array
    int dp[rows+1][cols+1];

    // last row and and last col will be set to inf
    for(int i=0; i<=rows; i++)
        dp[i][cols] = INT_MAX;

    for(int i=0; i<=cols; i++)
        dp[rows][i] = INT_MAX;

    // as we can only go down and right 
    // set 0 for the positions in dp we will use to build ans from the last element in grid
    // as last element can not be added with any numbers
    dp[rows-1][cols]=0; // right to arr
    dp[rows][cols-1]=0; // down to arr


    for(int i=rows-1; i>=0; i--){

        for(int j=cols-1; j>=0; j--){

            dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);

        }

    }

    return dp[0][0];
}

int main(void){

    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid);
}