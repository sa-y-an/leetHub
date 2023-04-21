class Solution {
public:
    
    // when encounter -1, maxi(ans) + at every step, 
    
    // find max pos sum with a neg num in the substr
    int cal(vector<int> nums){
        
        int n = nums.size();
        
        int lastNeg = -1;
        for( int i = n-1; i >= 0 ; i--) {
            if( nums[i] < 0 ) {
                lastNeg = i ;
                break;
            }
        }
        
        bool haveNeg = false;
        int curr = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ){
            int x = nums[i];
            
            if( x < 0 ) haveNeg = true;
            curr += x;
            
            if( curr < 0 ) {
                if( i < lastNeg ) curr = 0, haveNeg = false;
                else curr = -1;
            }
            
            else if( haveNeg ) ans = max(curr,ans);   
        }
        
        return ans;
    }
    
    // replace a -> 1 , b -> -1 and find max
    int replace(string &s, char a, char b){
        vector <int> nums;
        for( auto ch : s){
            if( ch == a ) nums.push_back(1);
            else if ( ch == b ) nums.push_back(-1);
        }
        return cal(nums);
    }
    
    int largestVariance(string s) {
        
        set <char> st(s.begin(),s.end());
        vector <char> store(st.begin(),st.end());
        
        int n = store.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < i ; j++){
                ans = max(ans,replace(s,store[i],store[j]));
                ans = max(ans,replace(s,store[j],store[i]));
            }
        }
        
        return ans;
    }
};