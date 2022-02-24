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