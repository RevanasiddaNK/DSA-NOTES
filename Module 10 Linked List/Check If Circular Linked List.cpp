struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/* Should return true if linked list is circular, else false */
class Solution {
  public:
    bool isCircular(Node *head) {
        if(head == NULL)
        return 1;

    Node* s = head->next;
   
     
    while( s != NULL && s != head)
            s = s->next;
    

    if(s == head)
        return 1;

    return 0;
    }
};
