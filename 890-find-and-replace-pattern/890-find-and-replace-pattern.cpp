class Solution {
public:
    
    vector <int> getPattern(string &a){
        vector <int> ans;
        unordered_map <char,int> mpp;
        int cnt = 0;
        for( char ch : a ){
            if( mpp.count(ch) == 0 ){
                mpp[ch] = cnt++;
            }
            ans.push_back(mpp[ch]);
        }
        
        return ans;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector <int> target = getPattern(pattern);
        vector <string> ans;
        for( auto &word : words ){
            vector <int> currPattern = getPattern(word);
            if( currPattern == target){
                ans.push_back(word);
            }
        }
        
        return ans;
        
    }
};