/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {

    int solve(Node *root, int k, int &i) {
        
        if(root == NULL)
            return -1;
            
        int left = solve(root->left,k,i);
        
        if(left != -1)
            return left;
            
        i++;
        
        if(i == k)
            return root->data;
        
        int right = solve(root->right,k, i);
        return right;
    }
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        
        int i = 0;
        return solve(root,K,i);
    }
};

