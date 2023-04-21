struct Trie{
private:
    vector <Trie*> child;
    bool isEnd;
public:
    
    Trie(){
        child.resize(26);
        isEnd = false;
    }
    
    void insert(string &word){
        Trie *node = this;
        for( char ch : word){
            if( !node->child[ch-'a'] )
                node->child[ch-'a'] = new Trie();
            node = node->child[ch-'a'];
        }
        node->isEnd = true;
    }
    
    string isMatch(string &word){
        Trie *node = this;
        string ans;
        for( char ch: word ){
            
            if( node->isEnd)
                return ans;
            
            if( !node->child[ch-'a'] )
                return "";
            
            ans.push_back(ch);
            node = node->child[ch-'a'];
        }
        
        if( node->isEnd)
            return ans;
        return "";
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        
        Trie trie;
        for( auto &word: dictionary){
            trie.insert(word);
        }
        
        int i = 0 , n = s.size();
        string ans;
        while( i < n ){
            
            string temp;
            while( i < n and s[i] != ' ')
                temp.push_back(s[i++]);
            string word = trie.isMatch(temp);
            if( word.size() )
                ans += word;
            else
                ans += temp;
            
            if( i < n ){
                ans += " ";
                i++;
            }
        }
        return ans;
    }
};