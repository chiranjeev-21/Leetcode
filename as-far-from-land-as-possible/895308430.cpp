
/*
==========================================================
Problem: As Far from Land as Possible
Difficulty: Medium
==========================================================

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 
Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.


Example 2:


Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.


 
Constraints:


	n == grid.length
	n == grid[i].length
	1 <= n <= 100
	grid[i][j] is 0 or 1

==========================================================
*/


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q, q1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        if (q.size() == n * n) {
            return -1;
        }
        int distance = 0;
        int dirx[4] = {-1, 0, 0, 1};
        int diry[4] = {0, 1, -1, 0};
        while (!q.empty()) {
            distance++;
            int m = q.size();
            for (int it = 0 ; it < m; it++) {
                auto [i, j] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int ni = i + dirx[k];
                    int nj = j + diry[k];
                     if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 0) {
                        grid[ni][nj] = distance;
                        q.push({ni, nj});
                     }
                }
            }
        }
        return --distance;
    }
};