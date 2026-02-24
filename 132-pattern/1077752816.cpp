
/*
==========================================================
Problem: 132 Pattern
Difficulty: Medium
==========================================================

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 
Example 1:


Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.


Example 2:


Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].


Example 3:


Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


 
Constraints:


	n == nums.length
	1 <= n <= 2 * 105
	-109 <= nums[i] <= 109

==========================================================
*/


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2)
            return false;
        vector<int> pref(n,INT_MAX);
        for(int i=1; i<n; i++){
            pref[i] = min(nums[i-1], pref[i-1]);
        }
        // for(auto i:pref){
        //     cout<<i<<" ";
        // }
        set<int> st;
        st.insert(nums[n-1]);
        for(int i=n-2; i>=1; i--){
            if(pref[i] + 1 < nums[i]){
                auto it = st.lower_bound(pref[i]+1);
                if(it != st.end() && (*it) < nums[i])
                    return true;
            }
            st.insert(nums[i]);
        }
        return false;
       
    }
};