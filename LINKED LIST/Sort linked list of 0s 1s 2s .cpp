
NOT WORKING  FOR STATICAL MEMORY ALLOCATION BUT WORKING FOR DYNAMIC MEMORY ALLOCATION 
toBeInserted NODE

class Solution
{
    void insert(Node* &tail, Node* temp){
        tail->next = temp;
        tail = tail->next;
    }
    
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        Node* curr = head;
        Node* ZeroHead = new Node(-1);
        Node* ZeroTail = ZeroHead;
        Node* OneHead = new Node(-1);
        Node* OneTail = OneHead;
        Node* TwoHead = new Node(-1);
        Node* TwoTail = TwoHead;
        
        while(curr != NULL){
            
            int a = curr->data;
            
            if(a == 0)
                insert(ZeroTail,curr);
                
            else if(a == 1)
                insert(OneTail,curr);
                
            else if(a == 2)
                insert(TwoTail,curr);
                
            curr = curr->next;
        }
        
        if(OneHead->next == NULL)
        {
            ZeroTail->next = TwoHead->next;
        }
        else
        {
            ZeroTail->next = OneHead->next;
          //  OneTail->next = TwoHead->next;
        }
        
        OneTail->next = TwoHead->next;
        TwoTail->next = NULL;
        
        head = ZeroHead->next;
        
        return head;
        
        delete ZeroHead;
        delete OneHead;
        delete TwoHead;
        
    }
};


