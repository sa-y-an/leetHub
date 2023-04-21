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
    
public:
    vector <vector <int>> ret;
    int target;
    
    void dfsSum(TreeNode* node, int acc = 0, vector <int> chosen = {} ){  
        // cout<<acc<<" "<<node->val<<"\n";
        if( node->right) {
            chosen.push_back(node->val);
            dfsSum(node->right,acc+node->val, chosen);
            chosen.pop_back();
        }
        if( node->left ) {
            chosen.push_back(node->val);
            dfsSum(node->left ,acc+node->val,chosen);
            chosen.pop_back();
        }
        if( (not node->right) and (not node->left) ){
            if ((acc+node->val)==target) {
                chosen.push_back(node->val);
                ret.push_back(chosen);   
                chosen.pop_back();
            }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if( not root ) return {};
        target = targetSum;
        dfsSum(root);
        return ret;
    }
};