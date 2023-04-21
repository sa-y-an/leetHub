class Solution {
public:
    string getSmallestString(int n, int k) {
        char ch = 'a';
        int usedUp = 0;
        string ans;
        for( int i = 0 ; i < n ; i++){      
            while( usedUp + (ch-'a'+1) + 26*(n-i-1) < k ) ch++;
            usedUp += ch-'a'+1;
            ans.push_back(ch);
        }
        return ans;
    }
};