
/*
==========================================================
Problem: Find Duplicate Subtrees
Difficulty: Medium
==========================================================

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 
Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]


Example 2:


Input: root = [2,1,1]
Output: [[1]]


Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]


 
Constraints:


	The number of the nodes in the tree will be in the range [1, 5000]
	-200 <= Node.val <= 200

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
    string dfs(TreeNode* node, string path, unordered_map<string,int>&tree_map,vector<TreeNode*>&res){
        if(node == NULL) return "null";
        //unique string describing every path down the tree's root
        //if this string is already present in our map, we have a duplicate subtree
        path += ","+to_string(node->val)+dfs(node->left,path,tree_map,res)+dfs(node->right,path,tree_map,res);
        cout<<path<<" ";
        if(tree_map.find(path)!=tree_map.end()){
            tree_map[path]+=1;
            if(tree_map[path]==2){
                res.push_back(node);
            }
        }
        else{
            tree_map[path]=1;
        }
        return path;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>res;
        unordered_map<string,int>tree_map;
        dfs(root,"",tree_map,res);
        return res;       
    }
};