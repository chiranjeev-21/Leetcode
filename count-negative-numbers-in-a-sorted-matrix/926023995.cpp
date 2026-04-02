
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

    int bin_search(vector<vector<int>>& grid, int i, int end){
        int start=0;
        // if(grid[i][end])
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(grid[i][mid]<0){
                if(ans==-1){
                    ans=mid;
                }
                else if(ans != -1){
                    ans=min(mid,ans);
                }
                end=mid-1;
            }
            // 1 -1 -1 -2
            else if(grid[i][mid]>=0){
                start=mid+1;
            }
        }
        // cout<<start<<end<<ans;
        return ans;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]<0){
                ans+=m;
            }
            else{
                int cnt=bin_search(grid,i,m-1);
                cout<<" "<<cnt<<" ";
                if(cnt!=-1){
                    ans+=m-cnt;
                }
            }  
        }
        return ans;
    }
};