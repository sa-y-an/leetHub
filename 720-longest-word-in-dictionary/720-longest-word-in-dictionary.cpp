class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set <string> good;
        int sz = 0;
        string ans;
        for( string &word: words ){
            if( word.size() == 1 ){
                good.insert(word);
                if( sz == 0 ){
                    sz = 1;
                    ans = word;
                }
                continue;
            }
            string temp = word;
            temp.pop_back();
            if( good.count(temp) > 0 ){
                if( word.size() > sz ){
                    sz = word.size();
                    ans = word;
                }
                good.insert(word);
            }
        }
        return ans;
    }
};