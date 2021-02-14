/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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


// recursion with vector slicing

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int max = inorder.size();
//         if(max == 0){
//             return nullptr;
//         }
        
//         TreeNode* root = new TreeNode(postorder[max-1]);
//         if(max>1){
//             int index=0;
//             for(int i=0;i<max;i++){
//                 if(inorder[i] == root->val){
//                     index = i;
//                     break;
//                 }
//             }
            
//             if(index>0){
//                 vector<int> ino(index);
//                 vector<int> pos(index);
//                 copy(inorder.begin(), inorder.begin()+index, ino.begin());
//                 copy(postorder.begin(), postorder.begin()+index, pos.begin());
//                root->left = buildTree(ino, pos);
//             }
//             if(index<max-1){
//                 vector<int> ino(max-index-1);
//                 vector<int> pos(max-index-1);
//                 copy(inorder.begin()+index+1, inorder.end(), ino.begin());
//                 copy(postorder.begin()+index, postorder.end()-1, pos.begin());
//                 root->right = buildTree(ino,pos);
//             }
//         }
//         return root;
//     }
// };

//
class Solution {
public:
    TreeNode* helper(vector<int>& ino, vector<int>& pos, int inoStart,int inoEnd, int posStart, int posEnd){
        TreeNode* root = new TreeNode(pos[posEnd-1]);
        if(inoEnd - inoStart > 1){
            int index=inoStart;
            for(int i=inoStart;i<inoEnd;i++){
                if(ino[i] == root->val){
                    index = i;
                    break;
                }
            }        
            if(index>inoStart){
               root->left = helper(ino, pos, inoStart, index, posStart, posStart+index-inoStart);
            }
            if(index<inoEnd-1){
                root->right = helper(ino,pos, index+1,  inoEnd, posStart+index-inoStart, posEnd-1);
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int l = inorder.size();
        if(l == 0){
            return nullptr;
        }
        return helper(inorder, postorder, 0, l, 0, l);
    }

};
