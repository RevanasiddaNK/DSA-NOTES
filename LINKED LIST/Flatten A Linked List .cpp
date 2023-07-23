
Flatten A Linked List
APPROACH  
{ Recursion,  Merge two soerted Linked Lists }
Time Complexity = O(N)
Space Complexity = O(N)
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
 
void insertAtTail(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == NULL && tail == NULL){
        head = temp;
        tail = temp;
        return;
    }
    
    tail->child = temp;
    tail = temp;
    
}

Node* merge2SortedLL(Node* &first , Node* &second){
    if(first == NULL)
        return second;
        
    if(second == NULL)
        return first;
        
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    while(first != NULL && second != NULL){
        if(first->data <= second->data){
            insertAtTail(ansHead,ansTail,first->data);
            first = first->child;
        }
        else
        {
            insertAtTail(ansHead,ansTail,second->data);
            second = second->child;
        }        
    }
    
    while(first != NULL){
        insertAtTail(ansHead,ansTail,first->data);
        first = first->child;
    }

    while(second != NULL){
        insertAtTail(ansHead,ansTail,second->data);
        second = second->child;
    }
    
    return ansHead;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL)
        return head;
    
    Node* temp1 = head;
    Node* temp2 = flattenLinkedList(head->next);
    
    head = merge2SortedLL(temp1,temp2);
    
    return head;
}
