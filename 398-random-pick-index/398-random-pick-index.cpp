class Solution {
    unordered_map <int, vector <int> > umap;
public:
    Solution(vector<int>& nums) {
        for( int i = 0 ; i < nums.size() ; i++ ){
            umap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int sz = umap[target].size();
        int idx = rand()%sz;
        return umap[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */