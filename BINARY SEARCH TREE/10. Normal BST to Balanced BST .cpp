//Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};

/*   Method 1
    Space Complexity = O(Height Of the Tree) 
    without using vector space
    Time Complexity = (N)
*/



/* Method 2 
Space Complexity = O(N) 
Time Complexity = (N)
*/
Node* BalancedTree(vector<int>&arr, int s, int e) {
    
    if(s > e)
        return NULL;
    
    int m = s+(e-s)/2;
    int val = arr[m];
    
    Node* root = new Node(val);
    
    root->left = BalancedTree(arr, s, m-1);
    root->right = BalancedTree(arr, m+1, e);
    
    return root;
}

void InorderTraversal(Node* root, vector<int>&arr) {
    
    if(root == NULL)
        return;
    
    InorderTraversal(root->left,arr);
    arr.push_back(root->data);
    InorderTraversal(root->right,arr);
   
}

// function should return root of the modified BST
Node* buildBalancedTree(Node* root)
{
    vector<int>arr;
    InorderTraversal(root,arr);
    
    int s = 0, e = arr.size()-1;  
    Node* ansRoot =  BalancedTree(arr, s, e);
    
    return ansRoot;
}
