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
    TreeNode* prev;
public:
    
    void dfs(TreeNode* root ){
        
        if( !root )
            return;
        
        dfs(root->right);
        dfs(root->left);
        
        root->left = nullptr;
        root->right = prev;
        prev = root;
    }
    
    void flatten(TreeNode* root) {
        prev = nullptr;
        return dfs(root);
    }
};