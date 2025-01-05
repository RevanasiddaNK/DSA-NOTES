/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    int i=0;
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(i <  k && curr != NULL  ){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
  
        i++;
    }

    if (i == k) {
        head->next = kReverse(curr, k);
        return prev;
    }
    else{
        curr = prev;
        prev = NULL;
        next = NULL;
        while( curr != NULL  ){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

}
