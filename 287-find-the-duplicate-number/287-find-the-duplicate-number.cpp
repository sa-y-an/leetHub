class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0 , fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if( slow == fast )
                break;
        }
        
        int merge = fast , head = 0;
        while( head != merge ){
            head = nums[head];
            merge = nums[merge];
        }
        
        return head;
    }
};