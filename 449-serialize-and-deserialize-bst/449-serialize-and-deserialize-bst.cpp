/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if( !root )
            return "";
        
        queue <TreeNode* > q;
        q.push(root);
        string ans;
        while( !q.empty()){
            auto curr = q.front();
            q.pop();
            if( curr ){
                ans += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }else{
                ans += "#,";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        const int n = s.size();
        if( n == 0 )
            return nullptr;
        
        int idx = 0;
        string r;
        while( idx < n and s[idx] != ',')
            r.push_back(s[idx++]);
        idx++;
        
        TreeNode* root = new TreeNode(stoi(r));
        queue <TreeNode* > q;
        q.push(root);
        
        while( !q.empty() and idx < n ){
            
            auto curr = q.front();
            q.pop();
            if( !curr )
                continue;
            
            vector <TreeNode*> v(2,nullptr);
            int k = 2;
            while( k-- ){  
                string temp;
                while( idx < n and s[idx] != ',')
                    temp.push_back(s[idx++]);
                if( temp[0] != '#' ){
                    v[1-k] = new TreeNode(stoi(temp));
                }
                idx++;
            }
              
            curr->left = v[0];
            curr->right = v[1];
            q.push(curr->left);
            q.push(curr->right);
            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;