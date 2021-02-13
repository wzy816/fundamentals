/*
113. Path Sum II
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.
A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]

Example 2:

Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:

Input: root = [1,2], targetSum = 0
Output: []

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
vector<vector<int>> ret;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root){
            vector<int> p;
            findPath(root, targetSum, p);
        }
        return ret;
    };
    
    void findPath(TreeNode* n, int t, vector<int> path){
        if(!n->left && !n->right){
            if(n->val == t){
                path.push_back(n->val);
                ret.push_back(path);
            }
        }
        path.push_back(n->val);
        if(n->left){
            findPath(n->left, t-n->val, path);
        }
        if(n->right){
            findPath(n->right, t-n->val, path);
        }
        return;
    };
};