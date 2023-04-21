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

typedef long ll;
class Solution {
public:
    
    bool isValidBST(TreeNode* root,ll upper = LONG_MAX, ll lower = LONG_MIN) {
        if( !root )
            return true;
        if( root->val <= lower or root->val >= upper )
            return false;
        return isValidBST(root->left,root->val, lower) and 
            isValidBST(root->right,upper,root->val); 
    }
};