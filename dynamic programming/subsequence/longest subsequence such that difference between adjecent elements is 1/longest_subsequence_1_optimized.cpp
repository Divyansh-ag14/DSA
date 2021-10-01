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
#include<unordered_map>
using namespace std;


// T: O(n)  S: O(n)
int longestSubsequence(int N, int A[]){

    unordered_map<int,int> m;
    int ans = 0;

    // for every number we only have to check for num+1 and num-1 values to build our ans

    for(int i=0; i<N; i++){

        int l = 0; // length of num+1 and num-1

        if(m[A[i]-1]) // if num-1 is present in map: set length to its value
            l = m[A[i]-1];

        if(m[A[i]+1] && m[A[i]+1]>l) // if num+1 is present: check if its bigger then current length, if yes update length
            l = m[A[i]+1];

        m[A[i]] = l+1; // current ans at num will be length + 1

        ans = max(ans, m[A[i]]); // at every point keep storing the max ans

    }

    return ans;

}

int main(void){

    // int N = 7, A[] = {10, 9, 4, 5, 4, 8, 6};

    int N = 5, A[] = {1, 2, 3, 4, 5};

    cout<<longestSubsequence(N, A);

}