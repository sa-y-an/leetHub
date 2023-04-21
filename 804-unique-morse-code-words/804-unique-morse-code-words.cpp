class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector <string> d = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map <char, string> umap;
        
        char letter = 'a';
        for( string &s : d ){
            umap[letter++] = s;
        }
        
        unordered_set <string> ans;
        
        for( auto &word : words ){
            string curr;
            for(char ch : word ){
                curr += umap[ch];
            } 
            ans.insert(curr);
        }
        
        return ans.size();
        
    }
};