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



Node* removeLoop(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* s = head;
    Node* f = head;
    while(f != NULL && f->next != NULL){

        s = s->next;
        f = f->next->next;

        if(s == f){
            Node* ans = s;
            s = head;
            while(s != f){
                s = s->next;
                f = f->next;
            }

            Node* prev = s;
            while(prev->next != s )
                prev = prev->next;
            prev->next = NULL;
           
            break;
        }
           
    }

    

    return head;
}
