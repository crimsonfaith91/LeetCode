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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(-1), *l1p = l1, *l2p = l2, *ap = ans;
        int carry = 0;
        
        while(l1p || l2p) {
            int l1val = l1p ? l1p->val : 0;
            int l2val = l2p ? l2p->val : 0;
            
            ap->next = new ListNode(l1val + l2val + carry);
            ap = ap->next;
                                    
            carry = (ap->val) / 10; 
            ap->val %= 10;
            
            if(l1p) l1p = l1p->next;
            if(l2p) l2p = l2p->next;
        }
        
        if(carry) ap->next = new ListNode(1);
        
        return ans->next;
    }
};