class Solution {
public:
    
    int largestContiguousOnes(vector <int> &arr){
        
        int ans = 0, n = arr.size(), cnt = 0;
        for( int x : arr){
            if( x == 1 ) cnt++;
            else ans = max(cnt, ans), cnt = 0;
        }
        return max(ans,cnt);
    }
    
    int longestValidParentheses(string s) {
        stack <int> st;
        vector <int> score;
        int n = s.size(), cnt = -1;
        
        for( int i = 0 ; i < n ; i++){
            auto ch = s[i];
            // invalid case 
            if( ch == ')' and st.empty()){
                cnt++, score.push_back(0);
            }
            // valid cases
            else {
                if( ch == '(' ){
                    st.push(++cnt);
                    score.push_back(0);
                }
                else {
                    auto idx = st.top();
                    st.pop();
                    score[idx] = 1;
                }
            }
        }
        
        int ans = largestContiguousOnes(score)*2;
        return ans;
        
    }
};