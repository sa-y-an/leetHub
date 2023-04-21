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
    TreeNode* root;
public:
    
    TreeNode* remove(TreeNode* root, const int key, TreeNode* parent = nullptr){
        
        if(!root)
            return nullptr;
        if( key == root->val){
            // leaf node
            if( !root->left and !root->right){
                if( !parent ) 
                    return parent;
                if( parent->left == root ) parent->left = nullptr;
                else parent->right = nullptr;           
                
                return root;
            }
            // if it has left child
            // its predecessor is lower in the tree
            else if( root->left ){
                // predecessor is the rightmost child of its left child
                TreeNode* predecessor = root->left;
                parent = root;
                while( predecessor->right ){
                    parent = predecessor;
                    predecessor = predecessor->right;
                }
                swap(predecessor->val, root->val);
                return remove(predecessor,key,parent);
                
            } 
            // if it has right child 
            else {
                
                // sucessor is lower down
                TreeNode* sucessor = root->right;
                parent = root;
                while( sucessor->left){
                    parent = sucessor;
                    sucessor = sucessor->left;
                }
                swap(sucessor->val, root->val);
                return remove(sucessor,key,parent);
            }    
        }
        else if( key > root->val )
            return remove(root->right,key,root);
        else
            return remove(root->left,key,root);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if( !root )
            return nullptr;
        if( root->val == key and (!root->left and !root->right))
            return nullptr;
        
        auto del = remove(root,key);
        if( key != root->val )
            return root;
        return del;
    }
};