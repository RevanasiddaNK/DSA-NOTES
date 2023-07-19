
class Solution
{
    public:
    
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL )
            return head;
        
        node* prev = NULL;
        node* curr = head;
        node* NEXT = NULL;
        int count = 0;
        
        while(count < k && curr != NULL){
            NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
            count++;
        }
        
        if(NEXT != NULL){
            head->next = reverse(curr,k);
        }
        
        return prev;
    }
};
