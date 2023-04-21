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
    vector <int> ans;
public:
    
    void preorderTraversal(Node* root){
        
        if( not root) return;
        ans.push_back(root->val);
        for( auto child : root->children){
            preorderTraversal(child);
        }
        
    }
    
    vector<int> preorder(Node* root) {
        preorderTraversal(root);
        return ans;
    }
};