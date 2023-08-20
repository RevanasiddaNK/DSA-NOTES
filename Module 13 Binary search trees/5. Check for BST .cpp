/*
2 Approaches
another approach is the Inorder traversal of BST is SORTED
Time complexity = O(N)
space complexity =  O(Height of the tree)

*/

class Solution
{
    public:
    
    bool check(Node* root, int min, int max) {
        
        if(root == NULL) 
            return true;
        int data = root->data;
        if(min < data && data < max) {
            bool left = check(root->left,min,data);
            bool right = check(root->right,data,max);

            return left && right;
            
        }
        else 
            return false;
    }
    
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        return check(root,INT_MIN, INT_MAX);
    }
};
