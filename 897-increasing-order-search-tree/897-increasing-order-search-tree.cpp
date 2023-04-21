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
    vector <TreeNode*> arr;
public:
    
    void inorder(TreeNode* root){
        if( not root) return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        int n = arr.size();
        for( int i = 0 ; i < n-1 ; i++){
            arr[i]->left = nullptr;
            arr[i]->right = arr[i+1];
        }
        arr[n-1]->right = arr[n-1]->left = nullptr;
        
        return arr[0];
    }
};