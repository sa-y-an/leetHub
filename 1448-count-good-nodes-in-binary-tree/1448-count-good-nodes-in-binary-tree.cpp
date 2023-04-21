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
    
    int valGreater( TreeNode* root, int maxSofar){
        
        if( not root )
            return 0;
        
        int ans = 0;
        if( root->val >= maxSofar )
            ans++;
        
        ans += valGreater(root->left, max(maxSofar,root->val));
        ans += valGreater(root->right, max(maxSofar,root->val)); 
        
        return ans;
        
    }
    
    int goodNodes(TreeNode* root) {
        
        return valGreater(root, INT_MIN);
    }
};