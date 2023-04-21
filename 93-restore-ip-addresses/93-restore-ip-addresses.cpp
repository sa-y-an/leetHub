class Solution {
    vector <string> ans;
public:
    

    void placeDots(string s, int idx, int k, int last){

      if( k == 0 ){
        if( s[0] == '0' and s[1] != '.' )
          return;
        long long num = stoll( s.substr(0,last+1));
        if( num <= 255)
          ans.push_back(s);
        return;
      }

      if( idx <= 0 )
        return;
      int n = s.size();
      if( (s[idx]-'0' > 0) || idx == n-1 || s[idx+1] == '.'){
        string newStr;
        long long num = stoll(s.substr(idx, last-idx+1));
        if( num <= 255 ){
          newStr = s.substr(0,idx) + "." + s.substr(idx,n-idx);
          placeDots(newStr,idx-1,k-1, idx);
        }
      }

      placeDots(s,idx-1,k,last);
    }

    vector<string> restoreIpAddresses(string s) {
      int n = s.size();
      placeDots(s,n-1,3, n-1);
      return ans;
    }
};