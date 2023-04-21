const vector <pair<int,int>> dz = {{-1,0},{0,-1},{1,0},{0,1}};
struct Trie{
    vector <Trie*> children;
    bool isEnd;
    string* word;
    
    Trie(){
        children.resize(26,nullptr);
        isEnd = false;
    }
    
    void insert(string &str){
        Trie* node = this;
        for( auto ch : str ){
            if( !node->children[ch-'a'] )
                node->children[ch-'a'] = new Trie();
            node = node->children[ch-'a'];
        }
        
        node->isEnd = true;
        node->word = &str;
    }
    
};

class Solution {
    vector <string> ans;
public:
    
    void dfs(vector<vector<char>>& board, int y, int x,Trie *node){
        
        int n = board.size(), m = board[0].size();
        char ch = board[y][x];
        if( !node->children[ch-'a'])
            return;
    
        board[y][x] = '#';
        Trie* child = node->children[ch-'a'];
        if( child->isEnd ){
            ans.push_back(*child->word);
            child->isEnd = false;
        }
        
        for( auto &[dy,dx] : dz ){
            int i = y + dy , j = x + dx;
            if( i >= 0 and i < n and j >= 0 and j < m and board[i][j] != '#')
                dfs(board,i,j,child);
        }
        
        board[y][x] = ch;
        
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie* root = new Trie();
        for( auto &word : words ){
            root->insert(word);
        }
        int n = board.size(), m = board[0].size(); 
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                dfs(board,i,j,root);
            }
        }
        
        return ans;
        
    }
};