#include<iostream>
#include<vector>
using namespace std;

int searchUtil(vector<int>& nums, int l, int r, int target){

    if(l>r) return -1;

    int m = (l+r)/2;

    if(nums[m] == target) return m; 

    if(nums[l] <= nums[m]){ // first half is sorted

        if(target>=nums[l] && target<=nums[m]) 
            return searchUtil(nums, l, m-1, target);

        return searchUtil(nums, m+1, r, target);
    }

    else{ // second half is sorted

        if(target>=nums[m] && target<=nums[r])
            return searchUtil(nums, m+1, r, target);

        return searchUtil(nums, l, m-1, target);
    }

}

int search(vector<int>& nums, int target){

    return searchUtil(nums, 0, nums.size()-1, target);
}

int main(void){
}