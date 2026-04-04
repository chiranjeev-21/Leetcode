
/*
==========================================================
Problem: Count Primes
Difficulty: Medium
==========================================================

Given an integer n, return the number of prime numbers that are strictly less than n.

 
Example 1:


Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.


Example 2:


Input: n = 0
Output: 0


Example 3:


Input: n = 1
Output: 0


 
Constraints:


	0 <= n <= 5 * 106

==========================================================
*/


class Solution {
public:
    int countPrimes(int n) {
        vector<bool>vec(n+2,true);
        vec[0]=false;
        vec[1]=false;
        vector<int>dp(n+2,0);
        for(int i=2;i<n;i++){
            if(vec[i]){
                for(int j=2*i;j<n;j+=i){
                    vec[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<n+2;i++){
            dp[i]=dp[i-1]+vec[i];
        }
        // for(auto i :dp){
        //     cout<<i<<" ";
        // }
        if(vec[n]){
            return dp[n]-1;
        }
        return dp[n];
    }
};