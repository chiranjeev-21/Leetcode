
/*
==========================================================
Problem: Best Time to Buy and Sell Stock IV
Difficulty: Hard
==========================================================

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 
Example 1:


Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.


Example 2:


Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


 
Constraints:


	1 <= k <= 100
	1 <= prices.length <= 1000
	0 <= prices[i] <= 1000

==========================================================
*/


class Solution {
public:
    int solver(int cap,vector<int> &p,int ind,bool buy,bool sell,vector<vector<vector<int>>> &dp){
       if(cap==0)return 0;
       if(ind==p.size())return 0; 
        if(dp[ind][cap][buy]!=-1)return dp[ind][cap][buy];
        if(buy){
            return dp[ind][cap][buy]=max(-p[ind]+solver(cap,p,ind+1,0,1,dp),solver(cap,p,ind+1,1,0,dp));
        }else{
            return dp[ind][cap][buy]=max(+p[ind]+solver(cap-1,p,ind+1,1,0,dp),solver(cap,p,ind+1,0,1,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (k+1, vector<int> (2,-1)));
        return solver(k,prices,0,1,0,dp);
    }
};