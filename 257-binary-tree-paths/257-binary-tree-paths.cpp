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
    vector <string> paths;
public:
    
    void inorder(TreeNode* root, string path = ""){
        
        if( not root ) return;
        
        if( path.empty()) path = to_string(root->val);
        else path += "->" + to_string(root->val);
        
        if( !root->left and !root->right) paths.push_back(path);
        
        if( root->left) inorder(root->left,path);
        if( root->right) inorder(root->right,path);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        inorder(root);
        return paths;
    }
};