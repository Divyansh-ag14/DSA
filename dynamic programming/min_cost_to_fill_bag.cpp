/*

Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, 
the task is to find the minimum cost to buy W kgs of oranges. 
If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.

Example:

Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5

Output: 14

Explanation: choose two oranges to minimize cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 

Constraints:
1 ≤ N, W ≤ 2*102
-1 ≤ cost[i] ≤ 105
cost[i] ≠ 0

*/

#include<bits/stdc++.h>
using namespace std;

int dp[201][201];

int util(int i, int w, int cost[]){

    if(i==-1) return 1e9; // if no elements are left to choose return max 

    if(w==0) return 0; // if a possible ans is found return 0

    if(dp[i][w] != -1) return dp[i][w]; // if dp array has some value: return it

    // use i+1 to make index start from 1
    // if index is greater than w or cost is less tgen 0: skip that element
    if(i+1 > w || cost[i] < 0) return util(i-1, w, cost); 

    // at every step we have 2 options

    int opt1 = cost[i] + util(i, w-(i+1), cost); // take the element: add its cost and subtract (index+1) value from weight
    int opt2 = util(i-1, w, cost); // skip that element

    return dp[i][w] = min(opt1, opt2); // store and return the max of both options

}

int minimumCost(int cost[], int N, int W){

    memset(dp, -1, sizeof(dp));

    int ans = util(N-1, W, cost);

    return ans==1e9 ? -1 : ans;

} 

int main(void){

    int N = 5, W = 5, arr[] = {20, 10, 4, 50, 100};

    cout<<minimumCost(arr, N, W);
}