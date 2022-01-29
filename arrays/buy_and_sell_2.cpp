/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

*/

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices){

    int proft=0;
    int n = prices.size();

    for(int i=1; i<n; i++){
        if(prices[i] > prices[i-1])
            proft += prices[i] - prices[i-1];
    }

    return proft;
}

int main(void){
}