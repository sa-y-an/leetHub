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
    int findBottomLeftValue(TreeNode* root) {
        
        queue <TreeNode*> q;
        q.push(root);
        TreeNode* prev = root;
        
        while( not q.empty()){
            
            auto ver = q.front();
            q.pop();     
            if( ver->right) q.push(ver->right);
            if( ver->left) q.push(ver->left);
            
            prev = ver;   
        }
        
        return prev->val;
    }
};