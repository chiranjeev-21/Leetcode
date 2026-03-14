
/*
==========================================================
Problem: Binary Tree Coloring Game
Difficulty: Medium
==========================================================

Two players play a turn based game on a binary tree. We are given the root of this binary tree, and the number of nodes n in the tree. n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x. The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player. In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn. If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player. If it is possible to choose such a y to ensure you win the game, return true. If it is not possible, return false.

 
Example 1:


Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
Output: true
Explanation: The second player can choose the node with value 2.


Example 2:


Input: root = [1,2,3], n = 3, x = 1
Output: false


 
Constraints:


	The number of nodes in the tree is n.
	1 <= x <= n <= 100
	n is odd.
	1 <= Node.val <= n
	All the values of the tree are unique.

==========================================================
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    int leftChildCount = 0;    // count of nodes in x's left subtree
    int rightChildCount = 0;   // count of nodes in x's right subtree

    // Helper function to count total nodes in a subtree
    int count(TreeNode* root, int x) {
        if (!root) return 0;

        int left = count(root->left, x);
        int right = count(root->right, x);

        // When we find node x, store the size of its subtrees
        if (root->val == x) {
            leftChildCount = left;
            rightChildCount = right;
        }

        return left + right + 1; // total nodes under this node
    }

public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x);  // fill leftChildCount and rightChildCount

        int parentSide = n - (leftChildCount + rightChildCount + 1);

        // Player 2 can win if any region (left/right/parent) has more than half the nodes
        if (leftChildCount > n / 2) return true;
        if (rightChildCount > n / 2) return true;
        if (parentSide > n / 2) return true;

        return false;
    }
};
