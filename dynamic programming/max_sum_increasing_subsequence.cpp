/*

Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 
Example:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 

Output: 106

Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100}

*/

#include<iostream>
using namespace std;

int maxSumIS(int arr[], int n){

    int dp[n];
    // dp array is initially same as given array (as if there is no sequence we will just return max value)
    for(int i=0; i<n; i++) dp[i] = arr[i];

    for(int i=0; i<n; i++){ // for every element in array

        for(int j=0; j<i; j++){ // iterate over all numbers till that element

            if(arr[i]>arr[j]) // if element is greater then the number
                dp[i] = max(dp[i], dp[j]+arr[i]); // store max of current ans  and current ans + number in array

        }

    }

    int ans=dp[0];

    for(int i=1; i<n; i++)
        ans = max(ans, dp[i]);

    return ans;

} 

int main(void){

    int N = 5, arr[] = {1, 101, 2, 3, 100}; 
    cout<<maxSumIS(arr, N);
}