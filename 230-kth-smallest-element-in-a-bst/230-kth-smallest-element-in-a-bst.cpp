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
    
    int res;
    int time;
    
    void inorder(TreeNode*root){
        
        if( not root or time == 0 ) return;
        
    
        inorder(root->left);
        time--;
        if( time == 0 ) {
            res = root->val;
            return;
        }
        
        inorder(root->right);
        
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        time = k;
        inorder(root);
        return res;
        
    }
};