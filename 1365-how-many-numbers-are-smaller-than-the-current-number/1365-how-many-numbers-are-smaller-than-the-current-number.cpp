class Solution {
public:
    // 1 2 2 3 8
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector <int> aux = nums;
        sort(aux.begin(),aux.end());
        int n = nums.size();
        vector <int> ans;
        for( int i = 0 ; i < n ; i++){
            int lb = lower_bound(aux.begin(),aux.end(),nums[i]) - aux.begin();
            ans.push_back(lb);
        }
        
        return ans;
    }
};