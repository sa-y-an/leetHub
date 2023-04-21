class Solution {
    int smallest_num;
public:
    bool can_form_m_grps(vector <int>& nums, int m, const int max_sum){
        if( smallest_num > max_sum ) return false;
        int curr_sum = 0, grps = 0, idx = 0 , n = nums.size();
        while( idx < n ){
            while( idx < n and curr_sum + nums[idx] <= max_sum ) curr_sum += nums[idx] , idx++;
            if( curr_sum == 0 ) return false;
            curr_sum = 0, grps++;
        }
        return grps <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        smallest_num = *min_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0), low = nums[0];
        int ans = 0;
        while( low <= high ){
            int mid = low + (high-low)/2;
            if( can_form_m_grps(nums,m,mid) ) ans = mid, high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
};