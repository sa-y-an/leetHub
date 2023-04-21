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
    
    bool getPath(TreeNode* root, TreeNode* target, vector <TreeNode*> &path){
        
        if( !root )
            return false;
        
        bool ans = false;
        if( root == target ){
            ans = true;
            path.push_back(root);
            return ans;
        }
        
        ans |= getPath(root->left, target, path);
        ans |= getPath(root->right, target, path);
        
        if( ans )
            path.push_back(root);
        
        return ans;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector <TreeNode*> path1, path2;
        getPath(root, p, path1);
        getPath(root, q, path2);
        
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        
        int i = 0;
        TreeNode* ans;
        while( i < min(path1.size(), path2.size()) and path1[i] == path2[i]){
            ans = path1[i++];
        }
        
        return ans;
    }
};