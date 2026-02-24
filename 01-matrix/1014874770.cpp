
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vec(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<int>dx = {-1,0,0,1};
        vector<int>dy = {0,1,-1,0};
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                for(int i=0;i<4;i++){
                    int new_dx = x + dx[i];
                    int new_dy = y + dy[i];
                    if(new_dx < n && new_dx >=0 && new_dy < m && new_dy>=0 && mat[new_dx][new_dy]!=0){
                        mat[new_dx][new_dy]=0;
                        vec[new_dx][new_dy]=cnt;
                        q.push({new_dx,new_dy});
                    }
                }
            }
        }
        return vec;
    }
};