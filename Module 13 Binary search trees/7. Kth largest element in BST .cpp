/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
     int solve(Node *root, int k, int &i) {
        
        if(root == NULL)
            return -1;
            
        int right = solve(root->right,k,i);
        
        // Answer sikkaga Maathra idu work aagutte
        if(right != -1)
            return right;
            
        i++;
        
        if(i == k)
            return root->data;
        
        int left = solve(root->left,k, i);
      //  idu mainly -1 and left ans annu return maadutte
        return left;
    }
    
    public:
    int kthLargest(Node *root, int K)
    {
        int i = 0;
        return solve(root,K,i);
    }
};
