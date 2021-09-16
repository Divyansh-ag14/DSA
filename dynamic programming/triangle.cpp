/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3

The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
*/


#include<iostream>
#include<vector>
using namespace std;


int minimumTotal(vector<vector<int>> &triangle){

    int rows = triangle.size();

    // if there is only 1 vector in triangle: return the 1st element (1st vector will always be of length 1)
    if(rows==1) return triangle[0][0];

    for(int i=rows-2; i>=0; i--){ // start from the second last vector

        for(int j=0; j<triangle[i].size(); j++) // for every element in that vector
            triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]); // find min sum and place it in itc loc. 

    }

    return triangle[0][0]; // the starting most element will have the ans

}

int main(void){


}