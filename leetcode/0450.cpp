/*
450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?
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

// step 1. find node
// step 2. delete node
// 2.1 zero child -> delete self
// 2.2 one child -> replace self with child
// 2.3 two children -> replace self with max of right tree

class Solution {
public:
    TreeNode* min(TreeNode* root){
        while(root && root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        // use recursion
        if(root->val > key){
            root->left =  deleteNode(root->left, key);
        }else if(root->val < key){
            root->right =  deleteNode(root->right,key);
        }else{
            // found
            // one or zero children
            if(root->left == nullptr || root->right == nullptr){
                return root->left == nullptr? root->right : root->left;
            }
            // two children
            TreeNode* n = min(root->right);
            root->val = n->val;
            root->right = deleteNode(root->right, n->val);
        }
        return root;
    }
};
