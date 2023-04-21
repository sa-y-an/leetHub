const int INF = 1e6;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack <pair<int, int>> st;
        int currMin = nums[0];
        
        for( int i = 1 ; i < nums.size() ; i++){
            int num = nums[i];
            while( not st.empty() and num >= st.top().first)
                st.pop();
            if( not st.empty() and num > st.top().second ) 
                return true;
            
            st.push({num,currMin});
            currMin = min(currMin,num);
        }
        return false;
    }
};