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

// bottom up: build solution from start
int rob(vector<int>& nums) {
     
    int n = nums.size();

    if(n==0) return 0;

    vector<int>dp(n); // dp array
    
    // if array length is 1: ans is the only element present
    if(n>=1) dp[0] = nums[0];
        
    // if array length is 2: store ans at 1st index
    if(n>=2) dp[1] = max(nums[0], nums[1]);
        
    // if array length is greater than 2
    // start from index 2: put value  at index that is max: check last element of dp array and curr+ adjecent element of d array  
    for(int i=2; i<n; i++)
        dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
            
    return dp[n-1];

}

int main(void){

    vector<int> nums = {1,2,3,1};

    cout<<rob(nums);
}

/*

ex: nums = [1,2,3,1]

n>=1(yes) dp[0]=1

n>=2(yes) dp[1]=2 (max(1,2));

if size is less then 3: 2 will be returned

else: for loop will be executed

dp[2] = max(dp[1], nums[2]+dp[0])
dp[2] = max(2, 3+1)
dp[2] = 4

dp[3] = max(dp[2], nums[3]+dp[1])
dp[3] = max(4, 1+3)
dp[3] = 4

dp = [1,2,4,4]

ans = dp[n-1] = dp[4-1] = dp[3] = 4

*/