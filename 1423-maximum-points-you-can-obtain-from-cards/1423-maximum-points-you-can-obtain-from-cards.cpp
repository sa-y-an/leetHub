class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = k, r = cardPoints.size();
        int ans = accumulate(cardPoints.begin(),cardPoints.begin()+l,0), 
        curr = ans;
        l--,r--;
        while( l >= 0 ){
            curr = curr - cardPoints[l] + cardPoints[r];
            ans = max(curr,ans);
            l--,r--;
        }
        
        return ans;
    }
};