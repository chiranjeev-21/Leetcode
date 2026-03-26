
/*
==========================================================
Problem: Coin Change
Difficulty: Medium
==========================================================

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 
Example 1:


Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1


Example 2:


Input: coins = [2], amount = 3
Output: -1


Example 3:


Input: coins = [1], amount = 0
Output: 0


 
Constraints:


	1 <= coins.length <= 12
	1 <= coins[i] <= 231 - 1
	0 <= amount <= 104

==========================================================
*/


class Solution {
public:

    int f(vector<int> &num, int target, int index, vector<vector<int>>& dp){
        if(index==0){
            if(target%num[index]==0){
                return target/num[index];
            }
            else{
                return 1e9;
            }
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int not_take = f(num,target,index-1,dp);
        int take = INT_MAX;
        if(target>=num[index]){
            take = 1 + f(num ,target - num[index],index,dp);
        }

        return dp[index][target]=min(not_take,take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(coins,amount,n-1,dp);
        return ans==1e9?-1:ans;
    }
};