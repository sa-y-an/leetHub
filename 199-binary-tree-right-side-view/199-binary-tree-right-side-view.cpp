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
    vector <vector<TreeNode*>> levelArr;
    unordered_map <TreeNode*, int> level;
public:
    vector<int> rightSideView(TreeNode* root) {
        // right view is basicallly the last elemnt of a level
        
        if ( not root ) return {};
        
        levelArr.resize(100);
        queue <TreeNode*> q;
        q.push(root);
        level[root] = 0;
        levelArr[level[root]].push_back(root);
        
        while( not q.empty()){
            
            auto curr = q.front();
            q.pop();
            
            if( curr->left ){
                q.push(curr->left);
                level[curr->left] = level[curr]+1;
                levelArr[level[curr->left]].push_back(curr->left);
            }
            if( curr->right){
                q.push(curr->right);
                level[curr->right] = level[curr]+1;
                levelArr[level[curr->right]].push_back(curr->right);
            }
            
        }
        
        vector <int> ans;
        for( auto &lvl : levelArr){
            if( lvl.size() == 0 ) break;
            ans.push_back(lvl.back()->val);
        }
        
        return ans;
    }
};