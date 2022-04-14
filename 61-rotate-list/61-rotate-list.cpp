class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        //edge cases
        if(head==nullptr || head->next==nullptr || k==0)
            return head;
        
        //compute length
        ListNode* curr=head;
        int len=1;
        while(curr->next){
            curr=curr->next;
            len++;
        }
        
        //go till that node
        curr->next=head;   //we joined last node with head
        k=k%len;
        k=len-k;
        while(k--)
            curr=curr->next;
        
        //make the node head and break connection
        //i.e in example 1 break 3 and 4 connection and making 4 as the head of linked list
        head=curr->next;
        curr->next=NULL;  // break the bond
        
        return head;
    }
};