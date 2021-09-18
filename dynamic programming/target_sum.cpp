/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

int dp[20005][25];
    
int util(vector<int>& nums, int target, int total, int i){
        
    if(i==-1 && total==target) return 1;
        
    if(i==-1 && total != target) return 0;
        
    if(dp[total+1000][i] != -1) return dp[total+1000][i];

    // for every element we have 2 options    
    int add = util(nums, target, total+nums[i], i-1);
    int sub = util(nums, target, total-nums[i], i-1);

    // since sum can be negative add 1000(max negative sum allowed) to make sure index is always positive 
    // return the number of ways from both the options   
    return dp[total+1000][i] = add+sub;
        
}
    
int findTargetSumWays(vector<int>& nums, int target) {
        
    memset(dp, -1, sizeof(dp));
        
    return util(nums, target, 0, nums.size()-1);
          
}

int main(void){
}