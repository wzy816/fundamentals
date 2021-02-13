/*
102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
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
int level;
vector<TreeNode*> t{};
vector<vector<int>> ret{};
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return ret;
        }
        t.push_back(root);
        level = 0;
        
        while(t.size()> 0){
            vector<TreeNode*> next_run{};
            vector<int> items;
            for(int i=0;i<t.size();i++){
                items.push_back(t[i]->val);
                if(t[i]->left){
                    next_run.push_back(t[i]->left);
                }
                if(t[i]->right){
                    next_run.push_back(t[i]->right);
                }
            }
            t = next_run;
            ret.push_back(items);
        }
        return ret;
    }
};