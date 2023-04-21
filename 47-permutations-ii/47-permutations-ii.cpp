class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set <vector <int>> perms;
        do{
            perms.insert(nums);    
        }while( next_permutation(nums.begin(),nums.end()));
        return vector <vector <int>> (perms.begin(), perms.end());
    }
};
