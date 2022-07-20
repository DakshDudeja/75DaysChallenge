class Solution {
public:
ListNode* reverse(ListNode *head){
	ListNode* prev =NULL;
	ListNode* curr=head;
    while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;

            prev=curr;
            curr=temp;
        }
	return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast = head;
        
        
        while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        }
        ListNode* nextHalf = reverse(slow);
        slow=head,fast=nextHalf ;
        while(slow and fast){
            if(fast->val!=slow->val) return false;
            else
                slow=slow->next;
                fast=fast->next;
        }
	return true;
    }
};
