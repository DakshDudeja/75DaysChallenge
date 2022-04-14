class Solution {
    
public:
       bool isPalindrome(ListNode* head) {
        if(!head || !(head->next))
        return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reversed(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
        
        
    }
    
    ListNode* reversed(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(head!=NULL){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
    return prev;
    }
};
