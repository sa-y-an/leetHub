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
    
    void reverseInorder(TreeNode* root, int &suffix ){
        if( not root ) return;
        reverseInorder(root->right, suffix);
        suffix += root->val;
        root->val = suffix;
        reverseInorder(root->left, suffix);
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        int suffix = 0;
        reverseInorder(root, suffix);
        return root;
    }
};