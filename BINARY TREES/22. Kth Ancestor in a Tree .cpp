
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/

// your task is to complete this function
Node * solve(Node* root, int &k, int node) {
    
    // Base Case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
        return root;
        
    Node* left = solve(root->left , k, node);
    Node* right = solve(root->right , k, node);
    
    if(left != NULL && right == NULL) {
        k--;
        if(k <= 0) {
             k = INT_MAX;
            return root;
        }
        return left;
    }
    
    else if(left == NULL && right != NULL) {
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        return right;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    
    if(ans == NULL || node == ans->data )
        return -1;
        
    else
        return ans->data;
}
