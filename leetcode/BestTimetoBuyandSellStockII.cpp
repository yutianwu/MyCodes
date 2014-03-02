/*
Best Time to Buy and Sell Stock II 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple 
transactions at the same time (ie, you must sell the stock before you buy again).
分析：
只要不亏就好
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int yesterday;
        int today;
        
        int profit = 0;
        if (prices.size() < 2) {
            return profit;
        }
        
        for (vector<int>::size_type i=1; i != prices.size(); i++) {
            yesterday = prices[i-1];
            today = prices[i];
            if (today > yesterday) {
                profit += today - yesterday;
            }
        }
        return profit;
    }
};