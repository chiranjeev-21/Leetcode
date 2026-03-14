
/*
==========================================================
Problem: Binary Tree Cameras
Difficulty: Hard
==========================================================

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 
Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.


Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.


 
Constraints:


	The number of nodes in the tree is in the range [1, 1000].
	Node.val == 0

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
    int cameras=0;
    int f(TreeNode* root){
        if(!root){
            return 2; // Null nodes are covered
        }
        int left = f(root->left);
        int right = f(root->right);

        //One Node is not covered
        if(left==0 || right==0){
            cameras++;
            return 1;
        }

        //This node can be covered by the camera placed on it's children
        if(left==1 || right==1){
            return 2;
        }
    
        //Both children covered
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (f(root) == 0) {
            cameras++;
        }
        return cameras;
    }
};