/*105. Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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

// sim to 0106
class Solution {
public:
        TreeNode* helper(vector<int>& pre, vector<int>& ino, int preStart,int preEnd, int inoStart, int inoEnd){
        TreeNode* root = new TreeNode(pre[preStart]);
        if(inoEnd - inoStart > 1){
            int index=inoStart;
            for(int i=inoStart;i<inoEnd;i++){
                if(ino[i] == root->val){
                    index = i;
                    break;
                }
            }        
            if(index>inoStart){
               root->left = helper(pre,ino, preStart+1, preStart+index-inoStart+1, inoStart, index);
            }
            if(index<inoEnd-1){
                root->right = helper(pre,ino, preStart+index-inoStart+1, preEnd, index+1, inoEnd);
            }
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l = inorder.size();
        if(l == 0){
            return nullptr;
        }
        return helper(preorder,inorder, 0, l, 0, l);        
    }
};