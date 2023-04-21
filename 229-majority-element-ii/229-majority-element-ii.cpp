class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int, int> umap;
        for( int x : nums ) umap[x]++;
        int n = nums.size()/3;
        vector <int> ans;
        for( auto &it : umap ) if( it.second > n ) ans.push_back(it.first);
        return ans;
    }
};