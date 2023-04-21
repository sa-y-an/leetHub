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
    vector <bool> umap;
    int ans = 0;
public:

    void check(){
        int curr = 0;
        for( bool val : umap ){
            if(val) curr++;
            if( curr > 1 ) return;
        }
        ans++;
    }
    
    void inorder(TreeNode* root){
        
        umap[root->val] = !umap[root->val];
        if( root->left) inorder(root->left);
        if (root->right) inorder(root->right);
        if( !root->left && !root->right ) check();
        umap[root->val] = !umap[root->val];
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
     
        umap.resize(10,false);
        inorder(root);
        return ans;
    }
};