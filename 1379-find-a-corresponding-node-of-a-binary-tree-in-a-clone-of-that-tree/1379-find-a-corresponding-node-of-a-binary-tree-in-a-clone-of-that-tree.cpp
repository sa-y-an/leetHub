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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue <TreeNode*> q1, q2;
        q1.push(original), q2.push(cloned);
        
        while( !q1.empty()){
            for( int sz = q1.size(); sz-- ; q1.pop(), q2.pop()){
                TreeNode* ver1 = q1.front(), *ver2 = q2.front();
                if( ver1 == target ) return ver2;
                if( ver1->left) q1.push(ver1->left), q2.push(ver2->left);
                if( ver1->right) q1.push(ver1->right), q2.push(ver2->right);
            }
        }  
        return nullptr;
    }
};