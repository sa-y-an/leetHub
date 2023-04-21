class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // fast
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0); 
        
        // code
        ListNode* l , *r = nullptr, *it;
        int cnt=0;
        for( it = head; it ; it = it->next ){
            if( r ) r = r->next;
            cnt++;
            if( cnt == k ) l = it , r = head;
        }
        swap(l->val, r->val);
        return head;
    }
};