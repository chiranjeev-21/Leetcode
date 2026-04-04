
/*
==========================================================
Problem: Count Servers that Communicate
Difficulty: Medium
==========================================================

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

 
Example 1:




Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Example 2:




Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.


Example 3:




Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.


 
Constraints:


	m == grid.length
	n == grid[i].length
	1 <= m <= 250
	1 <= n <= 250
	grid[i][j] == 0 or 1

==========================================================
*/


// class Solution {
// public:

    // int bfs(vector<vector<int>>& grid, int n, int m, int i, int j){
    //     queue<pair<int,int>>q;
    //     q.push({i,j});
    //     grid[i][j]=0;
    //     vector<int>dx={0,0,-1,1};
    //     vector<int>dy={1,-1,0,0};
    //     int ans=1;
    //     while(!q.empty()){
    //         int x=q.front().first;
    //         int y = q.front().second;
    //         q.pop();
    //         for(int k=0;k<4;k++){
    //             int new_dx = x + dx[k];
    //             int new_dy = y + dy[k];
    //             if(new_dx>=0 && new_dx<n && new_dy>=0 && new_dy<m && grid[new_dx][new_dy]==1){
    //                 q.push({new_dx,new_dy});
    //                 ans++;
    //                 grid[new_dx][new_dy]=0;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // int countServers(vector<vector<int>>& grid) {
        // int n=grid.size();
        // int m=grid[0].size();
        // int result=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==1){
        //             int ans = bfs(grid,n,m,i,j);
        //             if(ans==1){
        //                 continue;
        //             }
        //             else{
        //                 result+=ans;
        //             }
        //         }
        //     }
        // }
        // return result;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();  
        vector<int> rowCount(n, 0), colCount(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};