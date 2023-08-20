/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* intersect(Node* head){
        Node* slow = head;
        Node* fast = head;
        Node* ans = NULL;
        bool s = 0;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                s = 1;
                break;
            }
        }
        if(s == 1 ){
            return slow;
        }
        else{
            return ans;
        }

    }

    Node* cycleNode(Node* head){
        Node* fast = intersect(head);
        if(fast == NULL)
            return fast;
        Node* slow = head;
        Node* prev = fast;
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    Node *detectCycle(Node *head) {

        if(head == NULL || head->next == NULL)
            return NULL;
        
        return cycleNode(head);
    }
    
Node *removeLoop(Node *head)
{   
    if(head == NULL || head->next == NULL)
        return head;
    
   Node* ans = detectCycle(head);
   if(ans == NULL)
        return head;
    

    Node* prev = ans;
    while( prev->next != ans ){
        prev = prev->next;
    }
    prev->next = NULL;
    return head;
}
