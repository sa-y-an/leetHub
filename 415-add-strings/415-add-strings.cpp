class Solution {
public:
    string addStrings(string &num1, string &num2) {
        int carry = 0, i1 = 0 , i2 = 0;
        string ans;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        while( carry or i1 < num1.size() or i2 < num2.size() ){
            
            int temp = 0;
            if( i1 < num1.size() ) temp += num1[i1]-'0', i1++;
            if( i2 < num2.size() ) temp += num2[i2]-'0', i2++;
            if( carry ) temp += carry;
            
            carry = temp/10;
            ans += to_string(temp%10);            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};