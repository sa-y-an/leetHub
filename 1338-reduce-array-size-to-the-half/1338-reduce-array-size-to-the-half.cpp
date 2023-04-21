class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map <int,int> umap;
        for( int num : arr )
            umap[num]++;
        
        vector <int> nums;
        for( auto &[_,y] : umap )
            nums.push_back(y);
            
        sort(nums.begin(),nums.end(), greater <int> ());
        
        int n = arr.size();
        int target = (n+1)/2;
        
        int ans = 0;
        int curr = 0;
        for( int x : nums ){
            curr += x;
            ans++;
            if( curr >= target )
                return ans;
        }
        
        return ans;
    }
};