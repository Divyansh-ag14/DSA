#include<iostream>
#include<vector>
using namespace std;

// T: O(n)   S: O(n)
int findUtil(int i, int arr[], vector<int>&dp){

    // base case: index becomes less then 0
    if(i<=-1) return 0;

    // memoization (very important)
    if(dp[i] != -1) return dp[i];

    // options
    int op1 = arr[i] + findUtil(i-2, arr, dp); // include the current element: then skip its adjecent element
    int op2 = findUtil(i-1, arr, dp); // leave the current element

    dp[i] = max(op1, op2); // update dp array 

    return dp[i];
}

int findMaxSum(int arr[], int n){

    vector<int> dp(n, -1);

    // start from the last - so there is no need to pass size
    return findUtil(n-1, arr, dp);
}


int main(void){

    int arr[] = {5,5,10,100,10,5};

    cout<<findMaxSum(arr, 6);
}