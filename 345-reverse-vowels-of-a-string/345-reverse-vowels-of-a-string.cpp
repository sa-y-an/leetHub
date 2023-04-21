class Solution {
public:
    bool isVowel(char c){
        return c == 'a' 
            || c == 'e'
            || c == 'i'
            || c == 'o'
            || c == 'u'
            || c == 'A'
            || c == 'E'
            || c == 'I'
            || c == 'O'
            || c == 'U';
    }
    
    string reverseVowels(string s) {
        int l = 0, h = s.size() - 1;
        while (l < h){
            if  (!isVowel(s[l])){
                l++;
            } else if (!isVowel(s[h])){
                h--;
            } else {
                swap(s[l], s[h]);
                l++;
                h--;
            }
        }
        return s;
    }

};
