/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    
    private:
    
    int height(Node *root){
        
        if(root == NULL)
            return 0;
            
        int h1 = height(root->left);
        int h2 = height(root->right);
        
        return max(h1,h2)+1;
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL)
                return 1;
                
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool s = abs(height(root->left) - height(root->right)) <= 1 ? 1:0;
        
        if(left && right && s)
            return true;
        else
            return false;
    }
};
