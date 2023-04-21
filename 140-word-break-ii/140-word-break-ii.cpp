struct Trie{
    vector <Trie*> children;
    bool isEnd;
    
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
    }
    
};

class Solution {
    vector <vector<int>> endings;
    Trie* root;
public:
    
    void addspace(string &s, int idx, Trie* node, vector <int> &curr ){
        
        int n = s.size();
        if( idx == n ){
            if( node->isEnd )
                endings.push_back(curr);
            return;
        }
        
        char ch = s[idx];
        if( !node->children[ch-'a'])
            return;
        
        Trie* child = node->children[ch-'a'];
        
        if( child->isEnd ){
            curr.push_back(idx);
            Trie* newNode = root;
            addspace(s,idx+1,newNode,curr);
            curr.pop_back();
        }
        
        addspace(s,idx+1,child,curr);
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        root = new Trie();
        for( auto &word: wordDict ){
            root->insert(word);
        }
        
        vector <int> temp;
        addspace(s,0,root,temp);
        
        int n = s.size();
        vector <string> ans;
        for( auto &ending : endings ){
            int l = 0;
            string curr;
            for( int r : ending ){
                curr += s.substr(l,r-l+1);
                curr += " ";
                l = r+1;
            }
            curr += s.substr(l,n-l+1);
            ans.push_back(curr);
        }
        
        return ans;
    }
};