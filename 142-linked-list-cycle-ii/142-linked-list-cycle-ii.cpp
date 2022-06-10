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
     if (!head || !head->next || !head->next->next) return NULL;

        ListNode* slow=head,*fast=head;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)break;
        }
        if(fast!=slow)return NULL;
        fast=head;
        if(slow==fast) return slow;
        while(fast){
            slow=slow->next;
            fast=fast->next;
            if(fast==slow)break;
        }
        return slow;
    }
};