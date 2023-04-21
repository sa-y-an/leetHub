class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return unordered_set <int> (nums.begin(),nums.end()).size() - (count(begin(nums), end(nums), 0) > 0);
    }
};