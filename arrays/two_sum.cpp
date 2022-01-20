/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// brute force: T = O(n^2)
vector<int> twoSum(vector<int>& nums, int target) {
        
    int n=nums.size();
    vector<int>ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

// optimized: S O(n)  T O(n)
vector<int> twoSum2(vector<int> &nums, int target){

    vector<int> ans;
    unordered_map<int,int> m; // create a map to store (element, index)

    for(int i=0; i<nums.size(); i++){

        // find the target-num value in map
        // if it is found: push the index value in map and current index
        if(m.find(target-nums[i]) != m.end()){

            ans.push_back(target-nums[i]);
            ans.push_back(i);
            return ans;
        }

        // store the index at position equal to element value
        m[nums[i]] = i;
    }

    return ans;

}

int main(void){
}
