class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        vector <int> indices;
        int n = s.size();
        
        for( int i = 0 ; i < n ; i++){
            if(isalpha(s[i]))
                indices.push_back(i);
        }
        
        if( indices.size() < 2 )
            return s;
        
        int l = 0 , r = indices.size()-1;
        while( l < r ){
            swap(s[indices[l++]] , s[indices[r--]]);
        }
        
        return s;
    }
};