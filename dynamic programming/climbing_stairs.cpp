/*

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

#include<iostream>
using namespace std;

int util(int n, int dp[]){

    if(n==0) return 1; // if we have reached the top: add 1 to ans
    if(dp[n]!=-1) return dp[n]; // if we already have some ans: return it

    // at every step we have 2 options: to take single step or double steps
    int one=0, two=0;
    if(n>=1) one = util(n-1, dp); // while taking single step make sure n is atleast 1
    if(n>=2) two = util(n-2, dp); // while taking double, make sure n is atleast 2

    return dp[n] = one + two; // add the result of both

}

int climbStairs(int n){

    int dp[n+1];

    for(int i=0; i<=n; i++) dp[i]=-1;

    return util1(n, dp);

}

int main(void){

    cout<<climbStairs(2);
}