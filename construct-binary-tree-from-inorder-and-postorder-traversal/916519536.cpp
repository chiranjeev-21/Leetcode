
/*
==========================================================
Problem: Construct Binary Tree from Inorder and Postorder Traversal
Difficulty: Medium
==========================================================

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 
Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]


Example 2:


Input: inorder = [-1], postorder = [-1]
Output: [-1]


 
Constraints:


	1 <= inorder.length <= 3000
	postorder.length == inorder.length
	-3000 <= inorder[i], postorder[i] <= 3000
	inorder and postorder consist of unique values.
	Each value of postorder also appears in inorder.
	inorder is guaranteed to be the inorder traversal of the tree.
	postorder is guaranteed to be the postorder traversal of the tree.

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
    vector<int>vec;
    unordered_map<int,int>map;
    TreeNode* dfs(int l, int r) {
        if(l > r){
            return NULL;
        }
        
        int t=vec[0];
        vec.erase(vec.begin());
        TreeNode* node = new TreeNode(t);
        
        int i = map[node->val];
        
        node->right = dfs(i+1,r);
        node->left = dfs(l,i-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int p : postorder){
            vec.push_back(p);
        }
        reverse(vec.begin(),vec.end());
        for (int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return dfs(0,inorder.size()-1);
    }
    
};