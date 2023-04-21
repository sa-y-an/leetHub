/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        
        while( true ){
            
            if( !fast || !slow || !fast->next || !slow->next)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast )
                break;
        }
        
        ListNode* meet = slow;
        while( head != meet){
            head = head->next;
            meet = meet->next;
        }
        
        return head;
        
    }
};