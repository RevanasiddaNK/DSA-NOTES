class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        Node* rightNode = curr->right;
        
        while(curr != NULL && rightNode != NULL) {
            
            if(curr->left == NULL && curr->right == NULL){
                curr = rightNode;
                rightNode = rightNode->right;
            }
            else if(curr->left == NULL && curr->right != NULL) {
                curr->right->right = rightNode;
                rightNode = curr->right;
                curr = curr->right;
            }
            else {
                
                curr->left->right = rightNode;
                rightNode = curr->right;
                curr->right = curr->left;
                curr = curr->left;
            }
        }
     
        curr = root;
        while(curr != NULL) {
            curr->left = NULL;
            curr = curr->right;
        }
    }
};
