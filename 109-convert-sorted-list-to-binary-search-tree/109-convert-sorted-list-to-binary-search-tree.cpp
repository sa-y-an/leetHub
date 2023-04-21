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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    ListNode* head;
public:
    
    TreeNode* dfs(int l , int r ){
        
        if( l > r)
            return nullptr;
        int mid = (l+r)/2;
        
        TreeNode* left = dfs(l,mid-1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = dfs(mid+1,r);
        
        return root;
    }
    
    
    TreeNode* sortedListToBST(ListNode* Head) {
        
        int n = 0;
        head = Head;
        for( auto it = head ; it ; it = it->next  )
            n++;
        
        return dfs(0,n-1);
    }
};