/*
108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 1){
            return new TreeNode(nums[0]);
        }if(nums.size() == 2){
            return new TreeNode(nums[1], new TreeNode(nums[0]), NULL);
        }else{
            int n = nums.size();
            int mid = n/2;
            vector<int> l = vector<int>(nums.begin(),nums.begin()+mid);
            vector<int> r = vector<int>(nums.begin()+mid+1,nums.end());
            TreeNode* node = new TreeNode(nums[mid], sortedArrayToBST(l), sortedArrayToBST(r));
            return node;
        }
    }
};
