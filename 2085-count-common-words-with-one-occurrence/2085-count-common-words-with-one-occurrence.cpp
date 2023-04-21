class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map <string,int> w1, w2;
        for( auto &str : words1) w1[str]++;
        for( auto &str : words2) if( w1.count(str) > 0 and w1[str] == 1 ) w2[str]++; 
        int ans = 0;
        for(auto &word: w2) if(word.second == 1) ans++;
        return ans;
    }
};