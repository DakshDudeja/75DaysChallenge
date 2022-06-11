
class Solution {
public:
    ListNode* solve(ListNode* head,int k,int &len){
        int t=k;
        ListNode* prev = NULL, *curr = head;
        while(t--){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        len=len-k;
        if(len>=k)  head->next = solve(curr,k,len);
        else head->next=curr;
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            len++;
        }
        return solve(head,k,len);
    }
};