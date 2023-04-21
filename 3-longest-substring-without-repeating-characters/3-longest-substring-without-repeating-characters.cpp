class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        unordered_set <char> st;
        int l = 0 , r = 0;
        int ans = 0;
        
        while( r < n and l <= r ){
            char ch = s[r];
            while( l <=r and st.count(ch) > 0 ){
                st.erase(s[l++]);
            }
            st.insert(ch);
            ans = max(ans, (int) st.size());
            r++;
        }
        
        return ans;
    }
};