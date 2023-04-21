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
    int postorderIdx;
    unordered_map <int,int> Imap;
public:
    
    
    TreeNode* build(vector <int> &postorder, int il, int ir){
        
        
        if( il > ir )
            return nullptr;
                
        TreeNode* root = new TreeNode(postorder[postorderIdx--]);
        root->right = build(postorder,Imap[root->val]+1,ir);
        root->left = build(postorder,il,Imap[root->val]-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        postorderIdx = n-1;
        for( int i = 0 ; i < n ; i++){
            Imap[inorder[i]] = i;
        }
        
        return build(postorder,0,n-1);
        
    }
};