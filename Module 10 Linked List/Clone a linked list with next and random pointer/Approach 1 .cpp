/* 
BY using Map Data Structure 

Clone a linked list with next and random pointer

Time Complexity = O(N*2)
Space Complexity = O(N) because of Map

*/
class Solution
{
    public:
    
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    
    
    Node *copyList(Node *head)
    {
        
        Node*  newHead = NULL;
        Node*  newTail = NULL;
        
        Node*  oldNode = head;
        
        while(oldNode != NULL){
            insertAtTail(newHead,newTail,oldNode->data);
            oldNode = oldNode->next;
        }
        
        Node* newNode = newHead;
        map<Node* , Node* >mapping;
        oldNode = head;
        while(oldNode != NULL){
            mapping[oldNode] = newNode;
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        

        oldNode = head;
        newNode = newHead;
        while(oldNode != NULL){
            newNode->arb = mapping[oldNode->arb];
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        
        return newHead;
    }

};
