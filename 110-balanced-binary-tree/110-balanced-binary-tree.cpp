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
    unordered_map <TreeNode*, int> dp;
public:
    
    int height(TreeNode* root){
        
        if( !root )
            return 0;
        if( dp.count(root) )
            return dp[root];
        int left = height(root->left);
        int right = height(root->right);
        return dp[root] = max(left,right)+1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        if( !root)
            return true;
        
        int l = height(root->left);
        int r = height(root->right);
        
        if( abs(l-r) > 1 )
            return false;
        
        return isBalanced(root->left) and isBalanced(root->right);
    }
};