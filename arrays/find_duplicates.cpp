/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// T: O(n) S: O(n)
int findDuplicate(vector<int> &nums){

    unordered_map<int,int> m;
    
    // store the frquency of elements in the map
    // here key represents the acutal element
    for(int i=0; i<nums.size(); i++){
        m[nums[i]]++;
    }

    for(auto i=m.begin(); i!=m.end(); i++){

        if(i->second > 1)
            return i->first;
    }

    return -1;

}

int main(void){
}