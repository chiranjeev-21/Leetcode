
/*
==========================================================
Problem: 01 Matrix
Difficulty: Medium
==========================================================

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 
Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]


Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]


 
Constraints:


	m == mat.length
	n == mat[i].length
	1 <= m, n <= 104
	1 <= m * n <= 104
	mat[i][j] is either 0 or 1.
	There is at least one 0 in mat.


 
Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

==========================================================
*/


class Solution {
public:

    bool check(int x,int y, int n, int m){
        return x>=0 &&  x<n && y>=0 &&y<m;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int n=mat.size();
         int m=mat[0].size();
         int cnt=0;
         vector<vector<int>>vec(n,vector<int>(m,0));
         vector<vector<bool>>vis(n,vector<bool>(m,0));
         queue<pair<int,int>>q;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
         }
         vector<int>dx = {0,0,-1,1};
         vector<int>dy = {1,-1,0,0};
        while(!q.empty()){
            int temp=q.size();
            cnt++;
            for(int i=0;i<temp;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int new_dx = x + dx[k];
                    int new_dy = y + dy[k];
                    if(check(new_dx,new_dy,n,m) && !vis[new_dx][new_dy] && mat[new_dx][new_dy]==1){
                        q.push({new_dx,new_dy});
                        vis[new_dx][new_dy]=1;
                        vec[new_dx][new_dy]=cnt;
                    }
                }
            }
        }

         return vec;
    }
};