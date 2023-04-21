class Solution {
public:
    
    string evaluate(string &s){
        string str;
        for( auto ch : s ){
            if( ch != '#') str.push_back(ch);
            else {
                if( str.size() > 0 ) str.pop_back();
            }
        }       
        return str;
    }
    
    
    bool backspaceCompare(string s, string t) {
        return evaluate(s) == evaluate(t);
    }
};