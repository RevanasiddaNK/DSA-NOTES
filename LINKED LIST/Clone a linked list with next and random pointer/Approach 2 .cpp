/*

BY Changing the LINKS in Linked List

    time complexity O(N)
    space complexity O(1)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    
    void insert(Node* &head, Node*  &tail, int d){
        Node* temp = new Node(d);
        
        // First Element in clone List
        if(head == NULL && tail == NULL){
            head = temp;
            tail = temp;
            return;
        }
        
        tail->next = temp;
        tail = temp;
        
    }

public:
    Node* copyRandomList(Node* head) {
        Node*  cloneHead = NULL;
        Node*  cloneTail = NULL;
        
        Node* original = head;
        Node* clone = NULL;
        
        // step.1 = creating clone List Using next 
        while(original != NULL){
            insert(cloneHead, cloneTail, original->val);
            original = original->next;
        }
        
        // step.2 = inserting clone List Nodes in between the Nodes of Original List
        clone = cloneHead;
        original = head;
        while(clone != NULL && original != NULL){
            
            Node*  Next = original->next;
            original->next = clone;
            original = Next;
            
            Next = clone->next;
            clone->next = original;
            clone = Next;
        }
    
        // step.3 = Random Pointing 
        clone = cloneHead;
        original = head;
        while(clone != NULL && original != NULL){
            
            if(original->random != NULL)
                clone->random = original->random->next;
            else
                clone->random = original->random;
                
        
            original = original->next;
            clone = clone->next;
        }
       
        
        // step.4 = Free the original and Clone List from Mixture
        
        clone = cloneHead;
        original = head;
        while(clone != NULL && original != NULL){
            
            original->next = clone->next;
            original = original->next;
            
            if(original != NULL)
                clone->next = original->next;
                clone = clone->next;
            
        }
        // Step.5 reuturn ansNode
        return cloneHead;
    }
};
