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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if( not root ) return {};
        bool direction = false;
        queue <TreeNode*> q;
        vector <vector <int>> ans;
        
        q.push(root);
        q.push(nullptr);
        
        vector <int> temp;
        
        while( not q.empty()){
            
            auto ver = q.front();
            q.pop();
            
            if( !ver ){
                if( temp.size() > 0 ) {
                    if( direction ) reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                if( q.empty() ) break;
                temp.clear();
                direction = !direction;
                q.push(nullptr);
            }
            else {
                temp.push_back(ver->val);
                if( ver->left) q.push(ver->left);
                if( ver->right ) q.push(ver->right);
            }
            
        }
        
        return ans;
    }
};