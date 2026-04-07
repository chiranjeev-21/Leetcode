
/*
==========================================================
Problem: Count Ways To Build Good Strings
Difficulty: Medium
==========================================================

Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:


	Append the character '0' zero times.
	Append the character '1' one times.


This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

 
Example 1:


Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.


Example 2:


Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".


 
Constraints:


	1 <= low <= high <= 105
	1 <= zero, one <= low

==========================================================
*/


class Solution {
public:

    int f(int low, int high, int counter, int zero, int one, vector<long long>& dp){
        if(counter==high){
            return 1;
        }
        if(counter>high){
            return 0;
        }
        if(dp[counter]!=-1){
            return dp[counter];
        }
        if(counter>=low && counter<=high){
            int zero_call=f(low,high,counter+zero,zero,one,dp);
            int one_call = f(low,high,counter+one,zero,one,dp);
            return dp[counter]= (1+zero_call%1000000007 + one_call%1000000007)%1000000007;
        }
        
        int zero_call=f(low,high,counter+zero,zero,one,dp);
        int one_call = f(low,high,counter+one,zero,one,dp);
        return dp[counter]=(zero_call%1000000007 + one_call%1000000007)%1000000007;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high+1,-1);
        return f(low,high,0,zero,one,dp);
    }
};