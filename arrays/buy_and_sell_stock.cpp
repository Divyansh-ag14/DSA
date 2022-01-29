/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

*/

#include<iostream>
#include<vector>
using namespace std;


// T: O(n^2)
int maxProfitBrute(vector<int> prices){

    int n = prices.size();
    int profit = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            profit = max(profit, prices[j] - prices[i]);

        }
    }

    return profit;

}

// T : O(n)
int maxProfitOptimal(vector<int> prices){

    int n = prices.size();
    int curr_price=prices[0];
    int profit=0;

    for(int i=1; i<n; i++){

        if(prices[i] < curr_price)
            curr_price = prices[i];

        if(profit < prices[i] - curr_price)
            profit = prices[i] - curr_price;
    }
}

int main(void){
}