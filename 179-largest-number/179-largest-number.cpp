bool comparator (string a, string b){
    return a+b > b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector <string> arr;
        int cnt = 0;
        for( auto x : nums ){ if( x == 0 ) cnt++;}
        if( cnt == nums.size()) return "0";
        
        for( int x : nums ) arr.push_back(to_string(x));
        sort( arr.begin(), arr.end(), comparator );
        
        string ans;
        for( auto &str : arr ) ans += str;
        
        return ans;
    }
};