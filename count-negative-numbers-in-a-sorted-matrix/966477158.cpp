
/*
==========================================================
Problem: Count Negative Numbers in a Sorted Matrix
Difficulty: Easy
==========================================================

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 
Example 1:


Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.


Example 2:


Input: grid = [[3,2],[1,0]]
Output: 0


 
Constraints:


	m == grid.length
	n == grid[i].length
	1 <= m, n <= 100
	-100 <= grid[i][j] <= 100


 
Follow up: Could you find an O(n + m) solution?

==========================================================
*/


class Solution {
public:
    int binarysearch(vector<int> nums , int low , int high) {
        int n = nums.size(); int ans = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid]>=0) low=mid+1;
            else if(nums[mid]<0) {
                ans = (n-mid);
                high=mid-1;
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(); int cnt=0;
        for(int i=0;i<m;i++) {
            cnt += binarysearch(grid[i], 0 , grid[i].size()-1);
        }
        return cnt;
    }
};