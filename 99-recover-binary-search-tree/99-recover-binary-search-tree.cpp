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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
public:
    void recur(TreeNode* &root){
        if(!root){
            return;
        }        
        recur(root->left);
        if(prev){
            if(!first && prev->val>=root->val){
                first = prev;
            }
            if(first && prev->val>=root->val){
                second = root;
            }
        }
        prev = root;
        recur(root->right);
    }
    void recoverTree(TreeNode* root){
        int temp;
        recur(root);
        temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
