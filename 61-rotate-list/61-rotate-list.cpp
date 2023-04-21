/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 0 1
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( not head || not k ) return head;
        int len = 0;
        ListNode* prev = nullptr, *it = head, *ans;
        while( it ) prev = it, it = it->next, len++;
        prev->next = head;
        int toBeNulled = len - (k%len)-1;
        if( toBeNulled < 0 ) return head;
        it = head;
        while(toBeNulled--) head = head->next;
        ans = head->next;
        head->next = nullptr;
        return ans;
    }
};