#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
        
    int c0=0, c1=0, c2=0, x=0;
        
    for(int i=0; i<nums.size(); i++){
            
        if(nums[i]==0) c0++;
        if(nums[i]==1) c1++;
        if(nums[i]==2) c2++;
    }
        
    for(int i=0; i<c0; i++) nums[x++] = 0;
    for(int i=0; i<c1; i++) nums[x++] = 1;
    for(int i=0; i<c2; i++) nums[x++] = 2;
        
       
}

int main(void){
}