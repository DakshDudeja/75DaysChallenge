class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(left>1){
            prev=curr;
            curr=curr->next;
            left--;
            right--;
        }
        ListNode *con = prev, *tail = curr;

        while(right>0){
            ListNode* temp=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=temp;
            right--;
            
        }
        if(con!=NULL){
            con->next=prev;
        }
        else{
            head=prev;
        }
        tail->next=curr;


        return head;
    }
};