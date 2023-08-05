int getMinInBST(Node* root) {

    Node* temp = root;
    int min = INT_MIN;
    while(temp != NULL) {
        min = temp->data;
        temp = temp->left;
    }
    return min;
}

int getMaxInBST(Node* root) {

    Node* temp = root;
    int Max = INT_MAX;
    while(temp != NULL) {
        Max = temp->data;
        temp = temp->right;
    }
    return Max;
}

