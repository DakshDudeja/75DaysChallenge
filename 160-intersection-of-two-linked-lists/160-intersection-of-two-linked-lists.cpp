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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode*temp1=a,*temp2=b;
        while(a and b){
            if(a==b)return a;
            a=a->next;
            b=b->next;
        }
        if(!a)a=temp2;
        if(!b)b=temp1;
        
        while(a and b){
            a=a->next;
            b=b->next;        
        }
        if(!a)a=temp2;
        if(!b)b=temp1;

        while(a and b){                        
            if(a==b)return a;
            a=a->next;
            b=b->next;
        }
        return nullptr;
    }
};