/*
110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int left = calHeight(root->left);
        int right = calHeight(root->right);
        if(abs(left-right) > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int calHeight(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int left = 0;
        int right = 0;
        if(node->left){
            left = calHeight(node->left);
        }
        if(node->right){
            right = calHeight(node->right);
        }
        return max(left+1,right+1);
    }
};