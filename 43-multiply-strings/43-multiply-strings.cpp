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
    
    string multiply(string &num1, string &num2) {
        if( num2.size() > num1.size()) return multiply(num2, num1);
        if( num2.size() == 1 and num2[0] == '0') return "0";
        int n1 = num1.size() , n2 = num2.size();
        
        int pos = 0;
        string ans ;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end()); 
        for( auto d2 : num2 ){
            int carry = 0;
            string temp;
            for( auto d1 : num1){
                int product = (d1-'0')*(d2-'0');
                product += carry;
                carry = product/10;
                temp += to_string(product%10);
            }
            if( carry) temp += to_string(carry);
            reverse(temp.begin(), temp.end());
            for( int i = 0 ; i < pos ; i++){
                temp.push_back('0');
            }
            pos++;
            ans = addStrings(ans,temp);
        }
        
        return ans;
        
    }
};