
/*
==========================================================
Problem: Count Square Submatrices with All Ones
Difficulty: Medium
==========================================================

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 
Example 1:


Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.


Example 2:


Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.


 
Constraints:


	1 <= arr.length <= 300
	1 <= arr[0].length <= 300
	0 <= arr[i][j] <= 1

==========================================================
*/


class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int res=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]>0 && i>0 && j>0){
                    int mini=min(mat[i-1][j],min(mat[i][j-1],mat[i-1][j-1]));
                    mat[i][j]=mini+1;
                }
                res+=mat[i][j];
            }
        }
        return res;
    }
};