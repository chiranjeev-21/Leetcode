
/*
==========================================================
Problem: Construct Binary Tree from Preorder and Inorder Traversal
Difficulty: Medium
==========================================================

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 
Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]


Example 2:


Input: preorder = [-1], inorder = [-1]
Output: [-1]


 
Constraints:


	1 <= preorder.length <= 3000
	inorder.length == preorder.length
	-3000 <= preorder[i], inorder[i] <= 3000
	preorder and inorder consist of unique values.
	Each value of inorder also appears in preorder.
	preorder is guaranteed to be the preorder traversal of the tree.
	inorder is guaranteed to be the inorder traversal of the tree.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size(),m=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[inorder[i]]=i;
        }
        return f(0,n-1,preorder,0,m-1,inorder,mp);
    }

    TreeNode* f(int preStart, int preEnd, vector<int>&preorder, int inStart, int inEnd, vector<int>& inorder, unordered_map<int,int>&mp){
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        int root = preorder[preStart];
        int root_in_inorder = mp[root];
        int left_subtree_elements = root_in_inorder - inStart;
        int right_subtree_elements = inEnd - root_in_inorder;
        TreeNode* root_node = new TreeNode(root);
        root_node->left = f(preStart + 1, preStart + left_subtree_elements,
                       preorder, inStart, root_in_inorder - 1, inorder, mp);
        root_node->right = f(preStart + left_subtree_elements + 1, preEnd,
                        preorder, root_in_inorder + 1, inEnd, inorder, mp);
        // root_node->left=f(preStart+1,preStart+1+left_subtree_elements,preorder,inStart+left_subtree_elements,root_in_inorder-1,inorder,mp);
        // root_node->right=f(preStart+1,preEnd,preorder,root_in_inorder+1,inEnd,inorder,mp);
        return root_node;
    }
};