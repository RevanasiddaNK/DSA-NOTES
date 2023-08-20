

// APPROACH 1 
class Solution
{
    public:
    void flatten(Node *root)
    {
        Node *curr = root, *pred;
        while(curr) {
            // pred means preDecessor
           if(curr->left) {
              pred = curr->left;
               
                while(pred->right)
                    pred = pred->right;
                    
                pred->right = curr->right;
                curr->right = curr->left;
                curr = curr->left;
           }
           else {
               curr = curr->right;
           }
        }
        
        curr = root;
        while(curr != NULL) {
            curr->left = NULL;
            curr = curr->right;
        }
    }
};


// APPROACH 1 OPTIMIZED
class Solution
{
    public:
    void flatten(Node *root)
    {
        Node *curr = root, *pred;
        while(curr) {
            
           if(curr->left) {
               
               pred = curr->left;
               
                while(pred->right)
                    pred = pred->right;
                    
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
           }
           
           curr = curr->right;
        }
    }
};



// APPROACH 2 trying not yet completed
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
