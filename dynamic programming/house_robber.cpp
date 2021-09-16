/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that 
adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken 
into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

*/
#include<iostream>
#include<vector>
using namespace std;

int robUtil(vector<int>& nums, vector<int>& dp, int n){

    // base case: index becomes less then 0
    if(n<=-1) return 0;

    // memoization (very important)
    if(dp[n] != -1) return dp[n];

    // options
    int opt1 = nums[n] + robUtil(nums, dp, n-2); // include the current element: then skip its adjecent element
    int opt2 = robUtil(nums, dp, n-1); // leave the current element

    dp[n] = max(opt1, opt2); // update the array

    return dp[n]; // return the ans
}

int rob(vector<int>& nums){

    int n = nums.size();
    vector<int> dp(n, -1);

    return robUtil(nums, dp, n-1);
}

int main(void){


}