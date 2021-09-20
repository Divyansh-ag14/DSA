/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, 
and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.
*/

#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int> & arr){

    int ans=arr[0], ma=arr[0], mi=arr[0];

    for(int i=1; i<arr.size(); i++){

        if(arr[i]<0) swap(ma, mi); // if the curr no. is negative: swap ma and mi 
                                  //  so that (ma becomes the least possible negative value when multiplied)
                                  // and mi becomes the highest

        // at every step keep track of max and mon values
        ma = max(arr[i], arr[i]*ma);
        mi = min(arr[i], arr[i]*mi);

        ans = max(ma, ans);

    }

    return ans;
}

int main(void){

    vector<int>arr = {-1, -2, -3};

    cout<<maxProduct(arr);
}