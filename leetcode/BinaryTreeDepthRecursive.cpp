/*
Maximum Depth of Binary Tree 
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
分析：
求解二叉树的深度可以用递归法来实现，首先是分别求左右两子树的高度，再将最大的加一就是树的总高度了
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        int depth = 0;
        if(root != NULL) {
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            depth = (left > right ? left : right) + 1; 
        }
        return depth;
    }
};