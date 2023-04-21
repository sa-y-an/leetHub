class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector <int> freq(26,0);
        for( auto ch : words[0]) freq[ch-'a']++;
        int n = words.size();
        for( int i = 1; i < n ; i++){
            vector <int> temp(26,0);
            for( auto ch : words[i]) temp[ch-'a']++;
            for( int j = 0 ; j < 26; j++) freq[j] = min(temp[j],freq[j]);
        }
        
        vector <string> ans;
        for(int i =0 ; i < 26 ; i++) {
            string temp;
            while(freq[i]--){
                ans.push_back(temp = 'a'+i);
            }
        }
        return ans;
    }
};