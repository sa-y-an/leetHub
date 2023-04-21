class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> uset(nums1.begin(),nums1.end());
        unordered_set <int> uset2(nums2.begin(),nums2.end());
        vector <int> ans;
        for( int x : uset2) {
            if(uset.count(x) > 0 ) ans.push_back(x);
        }
        return ans;
    }
};