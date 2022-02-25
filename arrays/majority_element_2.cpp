#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> majorityElement(vector<int> &nums){

    int n=nums.size();
    unordered_map<int,int>m;
    vector<int>ans;

    for(int i=0; i<n; i++)
        m[nums[i]]++;

    for(auto it: m){

        if(it.second > n/3) 
            ans.push_back(it.first);

    }

    return ans;
    
}

int main(void){
}