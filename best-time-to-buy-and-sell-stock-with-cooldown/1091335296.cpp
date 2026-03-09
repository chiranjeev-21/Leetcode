
/*
==========================================================
Problem: Best Time to Buy and Sell Stock with Cooldown
Difficulty: Medium
==========================================================

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:


	After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).


Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 
Example 1:


Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]


Example 2:


Input: prices = [1]
Output: 0


 
Constraints:


	1 <= prices.length <= 5000
	0 <= prices[i] <= 1000

==========================================================
*/


class Solution {
public:

    int f(int i, vector<int>& prices, bool buy, vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            profit = max(-prices[i]+f(i+1,prices,0,dp),f(i+1,prices,1,dp));
        }
        else{
            profit = max(prices[i]+f(i+2,prices,1,dp), f(i+1,prices,0,dp));
        }
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
        return f(0,prices,1,dp);
    }
};