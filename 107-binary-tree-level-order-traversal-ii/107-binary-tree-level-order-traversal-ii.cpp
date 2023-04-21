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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if( not root) return {};
        vector <vector <int>> ans;
        ans.push_back({root->val});
        
        queue <TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        vector <int> temp;
        while( !q.empty()){
            
            auto ver = q.front();
            q.pop();
            
            if( !ver ){
                if( temp.size() > 0 ) ans.push_back(temp);
                if( q.empty()) break;
                temp.clear();
                q.push(nullptr);
            }else {
                if( ver->left ) q.push(ver->left), temp.push_back(ver->left->val);
                if( ver->right ) q.push(ver->right), temp.push_back(ver->right->val);
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};