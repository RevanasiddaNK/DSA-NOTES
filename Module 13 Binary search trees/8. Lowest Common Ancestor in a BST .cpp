2 Approaches
// Method 1 Iterative Solution
/*
    Time Complexity: O(Height of the BST).
    Auxiliary Space: O(1)
*/
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            if(root == NULL)
                return root;
            
            while(root != NULL) {
               if(root->data < n1 && root->data < n2)
                    root = root->right;
            
                else if(root->data > n1 && root->data > n2)
                    root = root->left;
            
                else
                    return root;
            }            
        }
};


// method 2 Recursive Solution
/*
    Time Complexity: O(Height of the BST).
    Auxiliary Space: O(Height of the BST).
*/
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            if(root == NULL)
                return root;
            
            else if(root->data < n1 && root->data < n2)
                return LCA(root->right,n1,n2);
            
            else if(root->data > n1 && root->data > n2)
                return LCA(root->left,n1,n2);
            
            else
                return root;
        }

};
