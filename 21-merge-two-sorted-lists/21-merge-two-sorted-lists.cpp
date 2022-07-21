
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* res = new ListNode(-101);
        ListNode* head = res;
        while(l1 and l2){
            if(l1->val < l2->val){
                res->next=new ListNode(l1->val);
                l1=l1->next;
            }
            else{
                res->next=new ListNode(l2->val);
                l2=l2->next;
            }
            res=res->next;
        }
        if(l1)res->next=l1;
        if(l2)res->next=l2;
        
        return head->next;
    }
};