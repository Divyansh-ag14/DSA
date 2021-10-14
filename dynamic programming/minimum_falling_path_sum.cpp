/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum are in (''):
[[2, '1', 3],      [[2, 1, '3'],
 [6, '5', 4],       [6, 5, '4'],
 ['7', 8, 9]]       [7, '8', 9]]


*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {

    // get the number of rows and cols from input matrix
    int rows = matrix.size();
    int cols = matrix[0].size();

    // start from the second last row: as last row can not be changed (no number after it to add)
    for(int i=rows-2; i>=0; i--){

        for(int j=0; j<cols; j++){ // for every element in row

            // we have 3 options
    
            int below = matrix[i+1][j]; // go exactly below it

            // go lower left (diagnal): check if current col is 0: we can not go more left from 0th col
            int below_left = j==0 ? INT_MAX : matrix[i+1][j-1];

            // go lower right (diagnal): check if we are at the last col: we can not move right from here
            int below_right = j==cols-1 ? INT_MAX : matrix[i+1][j+1];

            // add min of three to current element
            matrix[i][j] += min(below, min(below_left, below_right));

        }

    }

    // after above for loops ans will be in the first row
    // iterate over it and return the min value

    int ans = matrix[0][0];

    for(int j=1; j<cols; j++)
        ans = min(ans, matrix[0][j]);

    return ans;

}


int main(void){

    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};

    cout<<minFallingPathSum(matrix);
}