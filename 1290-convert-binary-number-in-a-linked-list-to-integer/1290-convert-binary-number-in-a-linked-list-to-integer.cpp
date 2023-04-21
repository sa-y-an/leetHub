/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector <bool> arr;
        for( auto it = head ; it ; it = it->next ){
            if( it->val == 1 ) arr.push_back(true);
            else arr.push_back(false);
        }
        int n = arr.size();
        int ans = 0 , expo = 0;
        for( int i = n-1 ; i >= 0 ; i--){
            if( arr[i] ) ans += pow(2,expo);
            expo++;
        }
        
        return ans;
    }
};