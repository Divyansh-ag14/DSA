/*

Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}

Output: 6

Explanation :Longest increasing subsequence [0 2 6 9 13 15], which has length 6

*/

#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

// T: O(nlogn)  S: O(n)
int longestSubsequence(int n, int a[]){

    int dp[n+1]; // index value of dp will be the ans (not element but index itself)
    dp[0]=INT_MIN; // as the least length can be 1
    for(int i=1; i<=n; i++) // fill rest of the dp array with INT_MAX;
        dp[i]=INT_MAX;

    // for every element in given array
    // find its upper bound idx (upper bound returns index of the next greatest number)
    // check if a[i] is  greater than dp[idx-1] and less then dp[idx]
    // as we are making > comparison with idx-1: take INT_MIN at pos 0 so at 1st index we get the first number
    // this ensures the ans is at least of length 1 which is the min possible length

    for(int i=0; i<n; i++){ // for every element in given array

        int idx = upper_bound(dp, dp+n+1, a[i]) - dp; // get its upper bound
    	
        // current number should be bigger then number at prev index
        // at every index store the min possible value
        if(a[i]>dp[idx-1] && a[i]<dp[idx]) // for the 1st iteration idx-1(0) is INT_MIN and idx(1) is INT_MAX, so it will always be true for 1st iter.
            dp[idx] = a[i];

    }

    int ans = 0;

    for(int i=n; i>=0; i--){

        if(dp[i]!=INT_MAX){
            ans=i;
            break;
        }

    }

    return ans;

}

int main(void){

    int N = 16, A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};

    cout<<longestSubsequence(N, A);
}