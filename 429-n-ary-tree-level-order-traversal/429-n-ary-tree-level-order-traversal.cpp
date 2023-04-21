/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    unordered_map <Node*,int> level;
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if( not root) return {};
        
        vector <vector <int>> levelArr;
        
        queue <Node*> q;
        q.push(root);
        level[root] = 0;
        levelArr.push_back({});
        levelArr[0].push_back(root->val);
        
        while( not q.empty()){
            
            auto curr = q.front();
            q.pop();
            if( curr == nullptr) continue;
            
            
            for( auto child : curr->children){
                level[child] = level[curr] + 1;
                if( levelArr.size() <= level[child] ) levelArr.push_back({});
                levelArr[level[child]].push_back(child->val);
                q.push(child);
            }
        }
        
        return levelArr;
        
    }
};