
/*
==========================================================
Problem: Find First and Last Position of Element in Sorted Array
Difficulty: Medium
==========================================================

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

 
Constraints:


	0 <= nums.length <= 105
	-109 <= nums[i] <= 109
	nums is a non-decreasing array.
	-109 <= target <= 109

==========================================================
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        if(binary_search(nums.begin(),nums.end(),tar)==false)
            return {-1,-1};
        int lb = lower_bound(nums.begin(), nums.end(), tar) - nums.begin();
        int ub = upper_bound(nums.begin(),nums.end(),tar)-nums.begin()-1;
        return {lb, ub};
    }
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     int start=0,end=n-1;
    //     int res=-1,res1=-1;
    //     if(nums.size()==0){
    //         return {-1,-1};
    //     }
    //     if(nums.size()==1 && nums[0]==target){
    //         return {0,0};
    //     }
    //     while(start<=end){
    //         int mid=start + (end-start)/2;
    //         if(nums[mid]==target){
    //             res=mid;
    //             end=mid-1;
    //         }
    //         else if(nums[mid]<target){
    //             start=mid+1;
    //         }
    //         else if(nums[mid]>target){
    //             end=mid-1;
    //         }
    //     }
    //     start=0;
    //     end=n-1;
    //     while(start<=end){
    //         int mid=start + (end-start)/2;
    //         if(nums[mid]==target){
    //             res1=mid;
    //             start=mid+1;
    //         }
    //         else if(nums[mid]>target){
    //             end=mid-1;
    //         }
    //         else if(nums[mid]<target){
    //             start=mid+1;
    //         }
    //     }
    //     // cout<<res<<" ";
    //     return {res,res1};
    // }
};