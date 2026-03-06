
/*
==========================================================
Problem: Balanced Binary Tree
Difficulty: Easy
==========================================================

Given a binary tree, determine if it is height-balanced.

 
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true


Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false


Example 3:


Input: root = []
Output: true


 
Constraints:


	The number of nodes in the tree is in the range [0, 5000].
	-104 <= Node.val <= 104

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

    int f(TreeNode * root,bool &flag){
        if(!root){
            return 0;
        }
        int lcall = f(root->left,flag);
        int rcall = f(root->right,flag);
        if(abs(rcall-lcall)>1){
            flag = false;
        }
        return 1+max(lcall,rcall);
    }

    bool isBalanced(TreeNode* root) {
        bool flag=true;
        f(root,flag);
        return flag;
    }
};