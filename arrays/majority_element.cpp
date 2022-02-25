/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 
Constraints:
n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1

*/


#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int majorityElement(vector<int> &nums){

    int n = nums.size();
    unordered_map<int,int>m;
    int ans=0;

    for(int i=0; i<n; i++)
        m[nums[i]]++;

    for(auto it: m){

        if(it.second>n/2){ ans=it.first; break; };

    }

    return ans;
}

// voting algo
// T: O(n)  S: O(1)

int majorityElementOptimized(vector<int> &nums){

    int n=nums.size();
    int count=0, ans=0;

    for(int i=0; i<n; i++){ 

        if(count==0){ // if count is 0: set it to 1 and mark ans as current element
            count=1, ans=nums[i];
        }

        else if(ans==nums[i]) count++; // if current element is same is prev: inc count

        else count--; // if elements are diff: dec count by 1

    }

    return ans;

}

int main(void){
}