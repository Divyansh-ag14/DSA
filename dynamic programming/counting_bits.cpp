/*

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

*/

#include<iostream>
#include<vector>
using namespace std;

// T: O(n)
vector<int> countBits(int n){

    vector<int> dp(n+1, 0);
    int offset=1;

    for(int i=1; i<=n; i++){

        if(offset*2==i) offset=i;

        dp[i] = 1 + dp[i-offset];

    }

    return dp;

}

int main(void){
}
