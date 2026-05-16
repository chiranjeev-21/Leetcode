
/*
==========================================================
Problem: Equal Row and Column Pairs
Difficulty: Medium
==========================================================

Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 
Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]


Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]


 
Constraints:


	n == grid.length == grid[i].length
	1 <= n <= 200
	1 <= grid[i][j] <= 105

==========================================================
*/


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<string>s_row,s_col;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<m;j++){
                str+=to_string(grid[i][j]);
                str+="$";
            }
            s_row.push_back(str);
        }

        for(int j=0;j<m;j++){
            string str="";
            for(int i=0;i<n;i++){ 
                str+=to_string(grid[i][j]);
                str+="$";
            }
            s_col.push_back(str);
        }
        // sort(s_row.begin(),s_row.end());
        // sort(s_col.begin(),s_col.end());
        int ans=0;
        for(int i=0;i<s_row.size();i++){
            for(int j=0;j<s_col.size();j++){
                if(s_row[i]==s_col[j]){
                    ans++;
                }
            }
        }
        
        // while(i<s_row.size() && j<s_col.size()){
        //     if(s_row[i]==s_col[j]){
        //         ans++;
        //         i++;
        //         j++;
        //     }
        //     else if(s_row[i]<s_col[j]){
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }
        for(auto i:s_row){
            cout<<i<<" ";
        }
        cout<<"\n";
        for(auto i:s_col){
            cout<<i<<" ";
        }
        return ans;
    }
};