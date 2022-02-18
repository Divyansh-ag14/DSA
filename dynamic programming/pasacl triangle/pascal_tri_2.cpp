/*

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]

*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex){

    vector<int> ans;
    vector<vector<int>> v(rowIndex+1);

    for(int i=0; i<=rowIndex; i++){

        v[i].resize(i+1);
    	v[i][0] = v[i][i] = 1;

        for(int j=1; j<i; j++)
            v[i][j] = v[i-1][j-1] + v[i-1][j];

    }

    for(auto i: v[rowIndex])
        ans.push_back(i);

    return ans;
}

int main(void){
}