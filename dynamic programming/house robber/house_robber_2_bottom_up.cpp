/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

*/

#include<iostream>
#include<vector>
using namespace std;

// same function as house_robber_bottom_up
int util(vector<int> &nums){

    int n = nums.size();

    if(n==0) return 0;

    vector<int> dp(n);

    if(n>=1) dp[0]=nums[0];

    if(n>=2) dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n; i++)
        dp[i] = max(dp[i-1], nums[i]+dp[i-2]);

    return dp[n-1];
}

int rob(vector<int> &nums){

    if(nums.size()==1) return nums[0];

    // make 2 subarrays 1 leaving the last element and one leaving the first element
    vector<int> a = {nums.begin(), nums.end()-1};
    vector<int> b = {nums.begin()+1, nums.end()}; 

    // compare ans of both arrays and return the max
    return max(util(a), util(b));
}

int main(void){

    vector<int> nums = {2,3,2};

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