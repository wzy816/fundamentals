/*297. Serialize and Deserialize Binary Tree
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

Example 4:

Input: root = [1,2]
Output: [1,2]

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
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

// preorder with -1001 as null marker
class Codec {
vector<int> d;
int index;

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        d.clear();
        preorder(root);    
        stringstream ss;
        copy(d.begin(),d.end(),ostream_iterator<int>(ss," "));
        string str = ss.str();
        cout << str << "\n";
        return str;
    }
    void preorder(TreeNode* node){
        if(!node){
            d.push_back(-1001);
        }else{
            d.push_back(node->val);
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string buf;
        d.clear();
        while(ss >> buf){
            d.push_back(atof(buf.c_str()));
        }
        index = 0;
        return helper();
    }
    
    TreeNode* helper(){
        int v = d[index];
        index++;
        if(v == -1001){
            return nullptr;
        }
        TreeNode* n = new TreeNode(v);
        n->left = helper();
        n->right = helper();
        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));