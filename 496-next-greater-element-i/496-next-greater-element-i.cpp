class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st;
        const int n = nums2.size();
        unordered_map <int, int> idxMap;
        vector <int> nge(n,-1), ans;
        for( int i= n-1 ; i >= 0 ; i--){
            idxMap[nums2[i]] = i;
            if( not st.empty() and st.top() > nums2[i] )
                nge[i] = st.top(), st.push(nums2[i]);
            else {
                while( not st.empty() and st.top() < nums2[i]) st.pop();
                if( not st.empty()) nge[i] = st.top();
                st.push(nums2[i]);
            }
        }
        for( auto num : nums1) ans.push_back(nge[idxMap[num]]);        
        return ans;
    }
};