/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
}; 
*/ 
class Solution {
public:
    Node* connect(Node* root) {
        if( not root) return root;
        queue <Node*> q;
        
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
        q.push(nullptr);
        root->next = nullptr;
        Node* prev = nullptr;
        
        while( not q.empty()){
            auto ver = q.front();
            q.pop();
            
            if( !ver ) {
                if( prev ) prev->next = nullptr;
                if(q.empty()) break;
                q.push(nullptr);
                prev = nullptr;
            }else {
                if(prev) prev->next = ver;
                if(ver->left) q.push(ver->left);
                if(ver->right) q.push(ver->right);
                prev = ver;
            }
        }
        return root;
    }
};