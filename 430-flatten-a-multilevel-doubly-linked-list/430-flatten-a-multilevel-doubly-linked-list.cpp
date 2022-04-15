
class Solution {
public:
    Node* flatten_rec(Node*head){
        Node* curr=head,*tail=head;
        while(curr){
            Node *child = curr->child;
            Node *next= curr->next;
            if(child){
                Node*tail = flatten_rec(child);
                
                tail->next = next;
                if(next) next->prev = tail;
                
                curr->next=child;
                child->prev = curr;
                
                curr->child = nullptr;
                
                curr=tail;
                
            }
            else
                curr = next;
            if(curr) tail=curr;
            
            }
        return tail;
        
    }
    Node* flatten(Node* head) {
        if(head)flatten_rec(head);
        return head;
    }
};