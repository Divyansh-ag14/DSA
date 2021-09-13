#include<iostream>
using namespace std;

int knapsackUtil(int N, int W, int val[], int wt[], int **dp){

    if(N== -1) return 0; // if no more elements left: return 0

    if(W==0) return 0; // if weight becomes 0: no need to search forward

    if(dp[N][W] != -1) return dp[N][W]; // if dp array has some value: return it

    if(wt[N] > W) return knapsackUtil(N-1, W, val, wt, dp); // if weight of element is more then required: skip it

    int take_item = val[N] + knapsackUtil(N, W-wt[N], val, wt, dp); // an item can be taken infinite times: (n is not decreased)
    int leave_item = knapsackUtil(N-1, W, val, wt, dp); // if item is not taken: n is decreased

    dp[N][W] = max(take_item, leave_item); // store the max value

    return dp[N][W]; 

}

int knapsack(int N, int W, int val[], int wt[]){

    int **dp = new int *[N];

    for(int i=0; i<N; i++){

        dp[i] = new int[W+1];

        for(int j=0; j<=W; j++)
            dp[i][j] = -1;

    }

    return knapsackUtil(N-1, W, val, wt, dp);

}

int main(void){

    int N = 4, W = 8 ,val[] = {1, 4, 5, 7}, wt[] = {1, 3, 4, 5};

    cout<<knapsack(N, W, val, wt);
}