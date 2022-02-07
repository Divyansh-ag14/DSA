/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []

*/


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


// TL O(n^3.logm)  S: O(m)
vector<vector<int>> threeSumBrute(vector<int>& nums){

    int n=nums.size();
    vector<vector<int>> ans;
    set<vector<int>> s;


    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){

                if(nums[i] + nums[j] + nums[k] == 0){

                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                
                }
            
            }
        }
    }

    for(auto i: s)
        ans.push_back(i);

    return ans;

}



int main(void){
}