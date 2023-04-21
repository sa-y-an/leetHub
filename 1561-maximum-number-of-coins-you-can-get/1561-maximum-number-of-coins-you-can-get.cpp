class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int cnt = 0;
        int ans = 0;
        for( int i = n-2 ; i >= 0 ; i -= 2){
            if( cnt == n/3) 
                break;
            ans += piles[i];
            cnt++;
            
        }
        
        return ans;
    }
};