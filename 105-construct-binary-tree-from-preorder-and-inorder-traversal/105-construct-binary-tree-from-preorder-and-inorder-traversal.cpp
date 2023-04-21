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
    int preorderIdx = 0;
    unordered_map <int,int> imap;
public:
    
    TreeNode* build( vector <int> &preorder, int il, int ir){
        
        if( il > ir )
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preorderIdx++]);
        root->left = build(preorder,il,imap[root->val]-1);
        root->right = build(preorder,imap[root->val]+1,ir);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        for( int i = 0 ; i < n ; i++)
            imap[inorder[i]] = i;
        return build(preorder,0,n-1);
    }
};