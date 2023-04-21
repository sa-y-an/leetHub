class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if( s.size() != goal.size() )
            return false;
        
        string one, two;
        for( int i = 0 ; i < s.size() ; i++){
            if( s[i] != goal[i] )
                one.push_back(s[i]),
                two.push_back(goal[i]);
        }
        
        if( one.size() == 0 ){
            set <char> st(s.begin(),s.end());
            return st.size() != s.size();
        }
        
        if( one.size() != 2 )
            return false;
        
        reverse(one.begin(),one.end());
        return one == two;
        
    }
};