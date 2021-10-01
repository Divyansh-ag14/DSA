/*
Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.

Example:

Input: N = 7

A[] = {10, 9, 4, 5, 4, 8, 6}

Output: 3

Explaination: The three possible subsequences 
{10, 9, 8} , {4, 5, 4} and {4, 5, 6}.
*/

#include<iostream>
using namespace std;

int longestSubsequence(int N, int A[]){

    int dp[N];

    // min length of sequence can be 1
    for(int i=0; i<N; i++) dp[i] = 1;

    for(int i=1; i<N; i++){ // start from the second element

        for(int j=0; j<i; j++){ // check prev elements upto ith-1 position

            if(abs(A[i]-A[j])==1) // if any numbers satisfy the condition
                dp[i] = max(dp[i], dp[j]+1); // store the max of current ans and ans at prev position + 1

        }

    }

    int ans=dp[0];

    for(int i=1; i<N; i++)
        ans = max(dp[i], ans);

    return ans;

}

int main(void){

    // int N = 7, A[] = {10, 9, 4, 5, 4, 8, 6};

    int N = 5, A[] = {1, 2, 3, 4, 5};

    cout<<longestSubsequence(N, A);
}