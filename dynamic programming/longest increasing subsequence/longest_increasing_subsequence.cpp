#include<iostream>
using namespace std;

// T: O(n^2)  S: O(n)
int longestSubsequence(int n, int a[]){
       
    int dp[n];
       
    for(int i=0; i<n; i++) dp[i]=1; // least possible ans is 1 
       
    for(int i=1; i<n; i++){ // for every element (starting from the second number)
        for(int j=0; j<i; j++){ // iterate over all numbers before it
             if(a[i]>a[j]) // number is smaller then element
                 dp[i] = max(dp[i], dp[j]+1); // store max of i and j (+1 to reach element from jth position)
        }
    }
        
    int mx=dp[0]; // find the max value in dp and return it
    for(int i=1; i<n; i++)
        mx  = max(mx, dp[i]);
          
    return mx;

}

int main(void){
}