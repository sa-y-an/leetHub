class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map <char, int> umap1 , umap2;
        for( auto i : word1) umap1[i]++;
        for( auto i : word2) umap2[i]++;
        
        vector <int> first, second;
        string str1, str2;
        for( auto it : umap1 ) first.push_back(it.second), str1.push_back(it.first);
        for( auto it : umap2 ) second.push_back(it.second), str2.push_back(it.first);
        
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        
        if( str1 != str2 ) return false;
        
        
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        return first == second;
    }
};