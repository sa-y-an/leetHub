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
    
    ListNode* reverse(ListNode* head, int k){
        
        if( !head || !head->next || !k )
            return head;
        
        ListNode* newHead = reverse(head->next,k-1);
        ListNode* oldNext = head->next->next;
        head->next->next = head;
        head->next = reverse(oldNext,1);
        return newHead;
    }
    
    ListNode* swapPairs(ListNode* head) {
        return reverse(head,1);
    }
};