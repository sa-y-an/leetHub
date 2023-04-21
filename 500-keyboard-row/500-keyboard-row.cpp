class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map <char, int> umap;
        string u1 = "qwertyuiop", u2 = "asdfghjkl", u3 = "zxcvbnm";
        for( auto i : u1) umap[i] = 1;
        for( auto i : u2) umap[i] = 2;
        for( auto i : u3) umap[i] = 3;
        
        vector <string> ans;
        
        for( auto word : words){
            int row = umap[tolower(word[0])];
            int cnt = 1;

            for( int i = 1 ; i < word.size() ; i++){
                if( umap[tolower(word[i])] != row ) break;
                cnt++;
            }
            
            if( cnt == word.size()) ans.push_back(word);
        }
        
        return ans;
    }
};