
/*
==========================================================
Problem: Climbing Stairs
Difficulty: Easy
==========================================================

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 
Example 1:


Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps


Example 2:


Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


 
Constraints:


	1 <= n <= 45

==========================================================
*/


class Solution {
public:

    int f(int i, int n, vector<int>& dp){
        if(i>n){
            return 0;
        }
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=f(i+1,n,dp) + f(i+2,n,dp);
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(0,n,dp);
    }
};