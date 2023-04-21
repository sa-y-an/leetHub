struct Trie{
    bool isEnd;
    vector <Trie*> children;
    
    Trie(){
        isEnd = false;
        children.resize(2,nullptr);
    }
    
    void insert(string &s){
        
        Trie* node = this;
        for( auto ch : s ){
            if( !node->children[ch-'0'])
                node->children[ch-'0'] = new Trie();
            node = node->children[ch-'0'];
        }
        
        node->isEnd = true;
    }
};


class Solution {
public:
    
    int decimal(string &bin){
        
        int ans = 0;
        for( int i = 31 ; i >= 0 ; i--)
            ans += pow(2,31-i)*(bin[i]-'0');
        
        return ans;
    }
    
    int maxXor(string &num, Trie* root){
        
        Trie *node = root;
        string ans;
        for( auto ch : num ){
            int val = ch-'0';
            val = 1-val;
            if( node->children[val] ){
                node = node->children[val];
                ans.push_back( '1');
            }else{
                node = node->children[ch-'0'];
                ans.push_back('0');
            }
        }
        
        return decimal(ans);
    }
    
    string binary(int x){
        string ans(32,'0');
        for( int i = 31 ; i >= 0 ; i--){
            if( ((x>>i)&1) )
                ans[31-i] = '1';
            else
                ans[31-i] = '0';
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        vector <string> dict;
        for( auto num : nums )
            dict.push_back(binary(num));
        
        Trie* root = new Trie();
        for( auto &num : dict ){
            root->insert(num);
        }

        int ans = 0;
        for( auto &num : dict ){
            ans = max(ans, maxXor(num,root));
        }
        
        return ans;
    }
};