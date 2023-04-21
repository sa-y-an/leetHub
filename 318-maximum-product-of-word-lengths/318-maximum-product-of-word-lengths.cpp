class Solution {
    vector <vector<bool>> dict;
public:
    
    void generateDict(vector<string>& words){
        int n = words.size();
        dict.resize(n, vector <bool> (26,false));
        for( int i = 0 ; i < n ; i++){
            string &word = words[i];
            for( int j = 0 ; j < word.size() ; j++){
                dict[i][word[j]-'a'] = true;
            }
        }
    }
    
    bool ifCommon(int i, int j){
        
        vector <bool> &cmap1 = dict[i];
        vector <bool> &cmap2 = dict[j];
        
        for( int i = 0 ; i < 26 ; i++){
            if( cmap1[i] and cmap2[i] ) return true;
        }
        return false;
    }
    
    
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        generateDict(words);
        
        unsigned long ans = 0;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < i ; j++){
                if( ifCommon(i,j)) continue;
                ans = max(ans, words[i].size()*words[j].size());
            }
        }
        
        return ans;
    }
};