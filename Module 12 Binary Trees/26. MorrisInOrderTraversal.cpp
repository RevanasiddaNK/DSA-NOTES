void MorrisTraversal(Node* root) {
    // TC O(N)
    // ASC O(1)
    Node *pred, *curr;
    curr = root;

    while(curr != NULL) {

        if(curr->left == NULL) {
            cout<<curr->data<<"  ";
           curr = curr->right;
        }
        else {
            pred = curr->left;

            while(pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if(pred->right == NULL) {
                pred->right = curr; 
                curr = curr->left;
            }
            else if(pred->right == curr) {
                // Removing Temporary Link
                pred->right = NULL;
                cout<<curr->data<<"  ";
                curr = curr->right;
            }
        }
    }
}
