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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if( left == right ) return head;
        ListNode* start, *end, *beforeStart, *afterEnd;
        
        int cnt = 1;
        for( auto it = head ; it ; it = it->next , cnt++){
            if( cnt == left -1 ) beforeStart = it;
            else if( cnt == left ) start = it;
            else if( cnt == right ) {
                end = it;
                break;
            }
        }
        afterEnd = end->next;
        
        // reverse the part
        auto prev = afterEnd;
        auto it = start;
        while( it != afterEnd ){
            
            auto tempNext = it->next;
            it->next = prev;
            prev = it;
            
            it = tempNext;
        }
        
        if( beforeStart ) {
            beforeStart->next = end;
            return head;
        }
        
        return end;
    }
    
};