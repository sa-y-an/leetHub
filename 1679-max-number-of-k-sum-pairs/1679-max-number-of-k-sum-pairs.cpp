class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> umap;
        for( int x : nums ) umap[x]++;
        
        int cnt =0;
        for( int num : nums ){
            int comp = k-num;
            if( umap[num] <= 0 || umap[comp] <= 0 ) continue;
            if( comp == num ){
                if( umap[comp] >= 2 ) umap[num] -= 2 , cnt++;
            }else umap[num]--, umap[comp]--, cnt++;   
        }
        return cnt;
    }
};