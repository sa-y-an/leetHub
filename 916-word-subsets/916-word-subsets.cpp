class Solution {
public:
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector <int> charMap(26,0);
        for( auto &word : words2 ){
            vector <int> currMap(26,0);
            for( char ch : word )
                currMap[ch-'a']++;
            for( int i = 0 ; i < 26 ; i++)
                charMap[i] = max(charMap[i],currMap[i]);
        }
        
        vector <string> ans;
        
        for( auto &word : words1 ){
            vector <int> currMap(26,0);
            for( char ch : word )
                currMap[ch-'a']++;
            int i = 0;
            for( i = 0 ; i < 26 ; i++)
                if( currMap[i] < charMap[i] )
                    break;
            
            if( i == 26 )
                ans.push_back(word);
        }
        
        return ans;
    }
};