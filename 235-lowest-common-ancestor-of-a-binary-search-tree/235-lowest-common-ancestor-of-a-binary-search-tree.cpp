/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mini = min(p->val,q->val);
        int maxi = max(p->val,q->val);
        
        while( root ){
            if( root->val <= maxi and root->val >= mini )
                return root;
            else if( root->val > maxi )
                root = root->left;
            else
                root = root->right;
        }
        
        return root;
    }
};