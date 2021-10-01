/*
You are given an array A of size N. The array contains integers and is of even length. 
The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, 
and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example:

Input:
N = 4
A[] = {5,3,7,10}

Output: 15

Explanation: The user collects maximumvalue as 15(10 + 5)
*/

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

long long util(int i, int j, int arr[]){

    if(i>j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // if we choose ith element: then other user can either choose the next ith element or jth element
    // if they choose ith element: we can choose from i+2 to j
    // if they choose jth element: we can choose from i+1 to j-1
    int opt1 = arr[i] + min(util(i+2, j, arr), util(i+1, j-1, arr));

    // if we choose jth element: then other user can either choose the ith element or j-1th element
    // if they choose ith element: we can choose from i+1 to j-1
    // if they choose jth element: we can choose from i to j-2
    int opt2 = arr[j] + min(util(i, j-2, arr), util(i+1, j-1, arr));

    // consider min of both cases as the other user is playing optimally too

    // store max of both the options
    return dp[i][j] = max(opt1, opt2);

}

long long maximumAmount(int arr[], int n){

    memset(dp, -1, sizeof(dp));

    return util(0, n-1, arr);

}

int main(void){

    int N = 4, A[] = {5,3,7,10};

    cout<<maximumAmount(A, N);

}