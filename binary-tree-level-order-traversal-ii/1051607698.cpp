
/*
==========================================================
Problem: Binary Tree Level Order Traversal II
Difficulty: Medium
==========================================================

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]


Example 2:


Input: root = [1]
Output: [[1]]


Example 3:


Input: root = []
Output: []


 
Constraints:


	The number of nodes in the tree is in the range [0, 2000].
	-1000 <= Node.val <= 1000

==========================================================
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>vec;
        if(root == NULL){
            return vec;
        }
        int len=0;
        while(!q.empty()){
            TreeNode *temp;
            len=q.size();
		    vector<int> v;
            for(int i=0;i<len;i++){
                temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left !=NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
		        vec.push_back(v);
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};