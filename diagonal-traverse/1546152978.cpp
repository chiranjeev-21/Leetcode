
/*
==========================================================
Problem: Diagonal Traverse
Difficulty: Medium
==========================================================

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 
Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]


Example 2:


Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]


 
Constraints:


	m == mat.length
	n == mat[i].length
	1 <= m, n <= 104
	1 <= m * n <= 104
	-105 <= mat[i][j] <= 105

==========================================================
*/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        //Simplest inutition:
        //Keep a flag variable that will tell you if you are moving up right or not.

        // while we have not reach the end of the row and column (last index for both row and column), follow the comments in the while loop
        if (matrix.size() == 0) return {};
        int iIndex = matrix.size(), jIndex = matrix[0].size();
        int i = 0, j = 0;
        bool isMovingUpRight = true;
        int count = 1;
        vector<int> result;
        result.push_back(matrix[0][0]);
        
        
        while (i != iIndex - 1 || j != jIndex - 1) {
            if (isMovingUpRight) { // if we are moving in the up-right direction...
                if (j == jIndex - 1) { // ...and we have hit the right end of the matrix, we will move down one position and switch direction
                    i++;
                    isMovingUpRight = false;
                } else if (i == 0) { // ...and we have hit the top the matrix, we will move right one position and switch direction
                    j++;
                    isMovingUpRight = false;
                } else { // ...else we have not hit the end of either side so we will move up and right one position
                    i--;
                    j++;
                }
            } else { // else we are moving in the bottom-left direction...
                if (i == iIndex - 1) { // ...and we have hit the bottom of the matrix, we will move right one position and switch direction
                    j++;
                    isMovingUpRight = true;
                } else if (j == 0) { // ...and we have hit the left end of the matrix, we will move down and switch direction
                    i++;
                    isMovingUpRight = true;
                } else { // ...else we have not hit the end of either side so we will move down and left one position
                    i++;
                    j--;
                }
            }
            
            result.push_back(matrix[i][j]);
        }
        return result;
    }
};