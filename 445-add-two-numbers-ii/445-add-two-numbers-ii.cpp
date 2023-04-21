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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;

    }
    
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode preHead(-1), *prev = &preHead;
        int carry = 0;
        while( l1 or l2 or carry ){
            
            int sum = (l1 ? l1->val : 0 ) + ( l2 ? l2->val : 0 ) + carry;
            prev->next = new ListNode(sum%10);
            carry = sum/10;
            prev = prev->next;
            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        
        return preHead.next;
    }

    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1), l2 = reverseList(l2);
        auto ans = addTwoNumbers2(l1,l2);
        return reverseList(ans);
    }
};