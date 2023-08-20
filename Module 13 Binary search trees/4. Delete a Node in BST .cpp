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

Node* DeleteNodeFromBST(Node* root, int data) {

    if(root == NULL) {
        return root;
    }

    else if(root->data == data) {

        // 0 childs
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } 

        // 1 chicld on right
        else if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 1 child on left
        else if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 childs
        else {
/*
            int max = getMaxInBST(root);
            root->data = max;
            root->left = DeleteNodeFromBST(root->left, max);
            return root;
*/          
            int mini = getMaxInBST(root);
            root->data = mini;
            root->right = DeleteNodeFromBST(root->right, mini);
            return root;

        }

    }

    else if(root->data > data) {
        root->left = DeleteNodeFromBST(root->left, data);
        return root;
    }
    else  {
        root->left = DeleteNodeFromBST(root->left, data);
        return root;
    }

}
