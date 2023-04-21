const int INF = 1e6;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) { 
        int small = INF, n = nums.size(), _max = 0;
        stack <int> st,s;
        for( int i = 0 ; i < n ; i++) {
            if( st.empty() or nums[st.top()] <= nums[i])st.push(i);
            else {
                while( !st.empty() and nums[st.top()] > nums[i] ) st.pop();
                int x = 0;
                if( !st.empty() ) x = st.top()+1;
                small = min(small, x);
                st.push(i);
            }
        }
        if( small == INF ) return 0;
        for( int i = n-1 ; i >= 0 ; i--){
            if( s.empty() or nums[s.top()] >= nums[i]) s.push(i);
            else {
                while( !s.empty() and nums[s.top()] < nums[i] ) s.pop();
                int x = n-1;
                if( !s.empty()) x = s.top()-1;
                _max = max(_max,x);
                s.push(i);
            }
        }
        return _max-small+1;
    }
};