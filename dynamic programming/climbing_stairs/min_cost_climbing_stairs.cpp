/*

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15

Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

*/

#include<iostream>
#include<vector>
using namespace std;

int util(vector<int>& cost, int dp[], int n){

    if(n<0) return 0; // if no more elements are present : we have reached the end

    if(dp[n]!=-1) return dp[n];

    int opt1 = util(cost, dp, n-1); // go to the next element (jump of 1)
    int opt2 = util(cost, dp, n-2); // skip the next element (jump of 2)

    return min(opt1, opt2) + cost[n];

}

int minCostClimbingStairs(vector<int>& cost) {
        
    int n = cost.size();
    int dp[n];
    for(int i=0; i<n; i++) dp[i]=-1;
    
    // we can either start fromt the 0th or 1st index
    return min(util(cost, dp, n-1), util(cost, dp, n-2));
        
}

int main(void){
}