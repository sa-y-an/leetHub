class Trie {
    struct Node{
        Node* child[26];
        bool isEnd = false;
    };
    Node* root;
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        Node* node = root;
        for( char ch : word ){
            if( !node->child[ch-'a'] ){
                node->child[ch-'a'] = new Node();
            }
            node = node->child[ch-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        
        Node* node = root;
        for( char ch : word ){
            if( !node->child[ch-'a'])
                return false;
            node = node->child[ch-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        
        Node* node = root;
        for( char ch : prefix ){
            if( !node->child[ch-'a'])
                return false;
            node = node->child[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */