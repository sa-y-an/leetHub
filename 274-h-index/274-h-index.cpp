class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort( citations.begin(), citations.end());
        int n = citations.size();
        int ans = 0;
        // 0 1 3 5 6
        for( int i = 0 ; i < n ; i++){
            int score = citations[i];
            int papers = n-i;
            int h = min(papers,score);
            ans = max(h,ans);
        }
        return ans;
        
    }
};