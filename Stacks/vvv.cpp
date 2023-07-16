class Solution
{
    private:
    struct Node* reverse(struct Node* &head){
         if(head  == NULL || head->next == NULL){
             return head;
         }
             
        struct Node* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
     }
     
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
       return reverse(head);
    }
    
};