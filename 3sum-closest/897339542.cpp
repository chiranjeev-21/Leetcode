
/*
==========================================================
Problem: 3Sum Closest
Difficulty: Medium
==========================================================

Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 
Example 1:


Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


Example 2:


Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).


 
Constraints:


	3 <= nums.length <= 500
	-1000 <= nums[i] <= 1000
	-104 <= target <= 104

==========================================================
*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size()-2 ; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;            
            while(left < right) {
                int curSum = nums[i]+nums[left]+nums[right];
                if(curSum == target){
                    return curSum;
                }
                if(abs(target-curSum)<abs(target-closest)){
                    closest = curSum;
                }
                if(curSum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return closest;
    }
};