APPROACH 1
/* 
 time complexity: O(N)
 auxiliary space: O(h) , where h = height of tree
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
    pair<bool, int> isBalancedFast(Node *root)
    {
        if(root == NULL){
            
            pair<bool, int>ans = make_pair(true,0);
            return ans;
            
        }
                
        pair<bool, int> left =  isBalancedFast(root->left);
        pair<bool, int> right =  isBalancedFast(root->right);
        
        bool s = abs(left.second - right.second) <= 1 ? 1:0;
        
        pair<bool, int>ans;
        if(left.first && right.first && s){
                ans.first = true;
                ans.second = (max(left.second , right.second)+1);
        }
        else
        {
            ans.first = false;
        }
        
        return ans;
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        pair<bool, int>ans = isBalancedFast(root);
        return ans.first;
    }
};





APPROACH 2
//    TIME COMPLEXITY = O(N^2)
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
