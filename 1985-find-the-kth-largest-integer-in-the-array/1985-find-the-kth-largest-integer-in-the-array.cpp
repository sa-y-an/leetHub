class Comparator {
public: 
    bool operator ()(string &a, string &b){
        if( a.size() != b.size() )
            return a.size() < b.size();
        return a < b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) { 
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + (n-k), nums.end(), Comparator());
        return nums[n-k];
    }
};
 