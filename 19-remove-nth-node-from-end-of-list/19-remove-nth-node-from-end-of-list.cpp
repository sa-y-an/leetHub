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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if( not head || not k ) return head;
        ListNode *right = nullptr, *prev = nullptr;
        int cnt = 1;
        for( auto it =  head ; it ; it = it->next, cnt++){
            if( right ) prev = right, right = right->next;
            if( cnt == k ) right = head;
        }
        
        if(!prev ) head = head->next;
        else prev->next = right->next;
        return head;
    }
};