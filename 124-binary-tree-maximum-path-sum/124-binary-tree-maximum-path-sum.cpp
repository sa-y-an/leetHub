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
const int INF = -1*1e9;
class Solution {
    int maxi;
public:
    
    int maxSum( TreeNode* root ){
        
        if( not root ){
            return INF;
        }
        int left = maxSum(root->left);
        int right = maxSum(root->right);
        int curr = root->val;
        int ans = max({curr+left, curr+right, curr});
        maxi = max({left,right,ans,curr+left+right,maxi});
        return ans;
    }
    
    int maxPathSum(TreeNode* root) {
        maxi = INF;
        int x = maxSum(root);
        return maxi;
    }
};