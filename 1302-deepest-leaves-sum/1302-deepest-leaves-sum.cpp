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
    int deepestLeavesSum(TreeNode* root) {
        
        queue <TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        int currsum = 0, ans = 0;
        
        while( not q.empty()){
            
            auto ver = q.front();
            q.pop();
            
            if( ver ){
                currsum += ver->val;
                if( ver->right) q.push(ver->right);
                if( ver->left ) q.push(ver->left );
            }
            else {
                ans = currsum;
                if( q.empty()) break;
                q.push(nullptr);
                currsum = 0;    
            } 
        }
            
        return ans;
    }
};