/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

*/

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>&prices){

    int n = prices.size();

    if(n==0) return 0;

    int curr_price = prices[0]; // initialize curr_price with first element
    int profit = 0; // profit is 0 initially

    for(int i=1; i<n; i++){
        
        // if curr element is less then buying price (do not sell just update buying price)
        if(prices[i] < curr_price)
            curr_price = prices[i];

        // else if the buying price is not getting lower and the profit increases at any point: consider it 
        else if(profit < prices[i] - curr_price)
            profit = prices[i] - curr_price;
    
    }

    return profit;

}

int main(void){

    vector<int> prices = {7,1,5,3,6,4};

    cout<<maxProfit(prices);
}