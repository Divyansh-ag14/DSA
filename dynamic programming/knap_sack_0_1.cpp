#include<iostream>
using namespace std;

int knapsackUtil(int W, int wt[], int val[], int **dp, int n){

    if(W==0 || n==-1) return 0; // if weight becomes 0 or n(index) becomes negative: return 0 as there is no need to traverse

    if(dp[n][W] != -1) return dp[n][W]; // if value is present at curr loc: return it

    if(wt[n] > W) // if weight is greater then required: leave that item
        return dp[n][W] = knapsackUtil(W, wt, val, dp, n-1);

    // for every element there are 2 options: take or leave
    // if the element is taken: add its value and subtract its weight from the total weight
    // if the element is not taken, move ahead and simply dec. the number of items
    int take_curr_item = val[n] + knapsackUtil(W-wt[n], wt, val, dp, n-1);
    int leave_curr_item = knapsackUtil(W, wt, val, dp, n-1);

    dp[n][W] = max(take_curr_item, leave_curr_item);

    return dp[n][W];

} 

int knapsack(int W, int wt[], int val[], int n){

    int **dp = new int*[n]; // 2d dp array

    for(int i=0; i<n; i++){ // rows equal to the number of items

        dp[i] = new int[W+1]; // columns equal to the total weight

        for(int j=0; j<=W; j++)
            dp[i][j] = -1; // fill it with -1

    }

    return knapsackUtil(W, wt, val, dp, n-1);

}

int main(void){

//    int  N = 3, W = 4, values[] = {1,2,3}, weight[] = {4,5,1};
//    cout<<knapsack(W, weight, values, N)<<endl;

   int N = 3, W = 3, values[] = {1,2,3}, weight[] = {4,5,6};
   cout<<knapsack(W, weight, values, N);
}