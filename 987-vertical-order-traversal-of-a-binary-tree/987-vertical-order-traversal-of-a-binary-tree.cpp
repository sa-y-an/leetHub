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
    map <int,map <int,vector <int>>> mpp;
public:
    
    void dfs(TreeNode* root, int y = 0 , int x = 0){
        
        if( !root ) return;
        mpp[x][y].push_back(root->val);
        dfs(root->left,y+1,x-1);
        dfs(root->right,y+1,x+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs(root);
        vector<vector<int>> ans;
        for( auto &[idx, xmpp]: mpp ){
            vector <int> curr;
            for( auto &[y,v] : xmpp ){
                sort(v.begin(),v.end());
                for( auto el : v ) curr.push_back(el);
            }
            ans.push_back(curr);
        }
            
        return ans;
    }
};