class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map <char, int> mpp, original;
        int n = text.size(), ans = text.size();
        string temp = "balloon";
        for( auto ch : temp){
            original[ch]++;
        }
        
        for( auto ch :  text){
            mpp[ch]++;
        }

        for( auto & [ch,cnt] : original){
            int curr = mpp[ch]/cnt;
            
            if( curr == 0 ) 
                return 0;
            ans = min(ans, curr);
            
        }
        
        return ans;
    }
};