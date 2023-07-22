#include <bits/stdc++.h> 
/**********************************************************************

    Following is the class structure of the Node class for reference:

    class Node{
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

********************************************************************/
Node* getmid(Node* &head){
    Node * slow = head;
    Node * fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;
        
    Node* temp = new Node(-1);
    Node* tail = temp;

    while(left != NULL && right != NULL){
        if(left->data < right->data){
            tail->next = left;
            tail = left;
            left = left->next;
        }
        else{
            tail->next = right;
            tail = right;
            right = right->next;
        }
    }

    while(left != NULL){
        tail->next = left;
        tail = left;
        left = left->next;
    }

    while(right != NULL){
        tail->next = right;
        tail = right;
        right = right->next;
    }

    return temp->next;
    delete temp;
}

Node* mergesort(Node* head){
    if(head == NULL || head->next == NULL)
        return head; 

    Node* mid = getmid(head);

    Node* left = head;
    Node* right = mid->next;

    mid->next = NULL;

    left = mergesort(left);
    right = mergesort(right);
    
    Node* result = merge(left,right);
    return result;
}

Node *sortLL(Node *head){

    return mergesort(head);
}
