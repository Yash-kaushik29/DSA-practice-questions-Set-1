class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=NULL and fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) break;
        }
        
        if(slow!=fast) return -1;
        
        slow=head;
        
        while(slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow->data;
    }
};
