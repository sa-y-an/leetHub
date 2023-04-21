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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode s(0);
        ListNode b(0);
        
        ListNode* small = &s, *big = &b;
        for( auto it = head ; it ; it = it->next ){
            if( it->val < x ){
                small->next = it;
                small = small->next;
            }else{
                big->next = it;
                big = big->next;
            }
        }
        big->next = nullptr;
        if( !s.next )
            return b.next;
        small->next = b.next;
        return s.next;
    }
};