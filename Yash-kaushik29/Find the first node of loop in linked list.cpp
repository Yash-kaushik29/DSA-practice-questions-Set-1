class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        Node* low=head;
        Node* high=head;
        
        while( high!=NULL && high->next!=NULL) {
            low=low->next;
            high=high->next->next;
            if(low==high) {
            break;
             }
         }
        Node* temp=head;
        if(low!=high) return -1;
        
        else {
            while(temp!=high) {
                temp=temp->next;
                high=high->next;
            }
        }
        
        return temp->data;
        
    }
};
