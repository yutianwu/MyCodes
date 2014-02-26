﻿/*
Same Tree
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

分析：
使用中序遍历两棵树，判断两棵树是否相等
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if(p == NULL || q == NULL) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        } 
        if (!isSameTree(p->left, q->left)) {
            return false;
        }
        if (!isSameTree(p->right, q->right)) {
            return false;
        }
        
        return true;
    }
};