
/*
==========================================================
Problem: 4Sum
Difficulty: Medium
==========================================================

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:


	0 <= a, b, c, d < n
	a, b, c, and d are distinct.
	nums[a] + nums[b] + nums[c] + nums[d] == target


You may return the answer in any order.

 
Example 1:


Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


Example 2:


Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


 
Constraints:


	1 <= nums.length <= 200
	-109 <= nums[i] <= 109
	-109 <= target <= 109

==========================================================
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int>s;
        vector<vector<int>>vec;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int newtarget=(long long int)target-nums[i]-nums[j];
                int l=j+1,r=n-1;
                while (l < r) {
                    if (nums[l] + nums[r] == newtarget) {
                        vec.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l; --r;
                        while (l < r && nums[l-1] == nums[l]) ++l; // Skip duplicate nums[l]
                    }
                    else if(nums[l] + nums[r] > newtarget){
                        r--;;
                    }
                    else{
                        l++;
                    }
                }
                while (j+1 < n && nums[j] == nums[j+1]) j++; // Skip duplicate nums[j]
            }
            while (i+1 < n && nums[i] == nums[i+1]) i++; // Skip duplicate nums[i]
        }
        return vec;
    }
};