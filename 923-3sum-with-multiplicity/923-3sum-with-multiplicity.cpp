class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        long m[101] = {}, res = 0;
        for (auto n : nums) ++m[n];
        for (auto i = 0; i < 101; ++i)
            for (auto j = i, k = target - i - j; j < 101; ++j, --k)
                if (k >= j && k < 101) 
                    res += m[i] * (m[j] - (i == j)) * (m[k] - (k == j) * ((i == j) + 1)) /
                    (((k == j && i == j) * 2 + 1) * ((k == j || i == j) + 1));
        return res % 1000000007;
        
    }
};