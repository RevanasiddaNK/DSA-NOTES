struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
Node* reverseDLL(Node * head)
{
    if(head == NULL || head->next == NULL)
        return head;
        
    Node* curr = head;
    Node* prev1 = NULL;
    
    while(curr != NULL){
        
        prev1 = curr->prev;
        curr->prev = curr->next;
        curr->next = prev1;
        
        curr = curr->prev;
    }
    
    return prev1->prev;
}
