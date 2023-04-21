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
    ListNode* next;
    int n;
    bool canGroup;
public:
    
    ListNode* rev(ListNode* head, int k){
        
        if( !head || !head->next || !k ){
            if( k )
                next = nullptr, canGroup = false;
            else
                next = head->next;
            return head;
        }
        
        ListNode* newHead = rev(head->next,k-1);
        if( !canGroup )
            return head;
        head->next->next = head;
        head->next = nullptr;
        if( k == n )
            head->next = rev(next,n);
        return newHead;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        n = k-1;
        canGroup = true;
        return rev(head,k-1);
    }
};