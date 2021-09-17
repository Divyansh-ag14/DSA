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

int util(vector<int> &nums, int **dp, int n, int last, bool flag){

    if(n<=-1) return 0; // if no element is left in array

    if(n==0 && flag) return 0; // if the index is and flag is 1(last element is taken): dont take the 1 (0th) index element

    if(dp[n][flag] != -1) return dp[n][flag]; // if dp array has some value: return it

    int opt1, opt2;

    if(n==last){ // only for the last element, flag is changed to 1

        opt1 = nums[n] + util(nums, dp, n-2, last, 1); // take the last element
        opt2 = util(nums, dp, n-1, last, flag); // leave the last element: (by default flag is 0)

    }

    else{ // if curr index is not of the last element: do the above with flag as 0

        opt1 = nums[n] + util(nums, dp, n-2, last, flag);
        opt2 = util(nums, dp, n-1, last, flag);

    }


    dp[n][flag] = max(opt1, opt2); // store max of both options in dp

    return dp[n][flag];

}

int rob(vector<int> &nums){

    int n = nums.size();
    
    // 2d dp array (store value and flag) flag=1 means last element is taken
    int **dp = new int*[n];

    for(int i=0; i<n; i++){

        dp[i] = new int[2]; // size is two as flag can take two values 0 and 1

        for(int j=0; j<2; j++)
            dp[i][j] = -1; // initially filled with -1

    }


    return util(nums, dp, n-1, n-1, 0);
    
}

int main(void){


}