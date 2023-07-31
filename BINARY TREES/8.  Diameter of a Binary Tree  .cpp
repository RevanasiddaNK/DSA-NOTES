/*
APPROACH 1   
    TIME COMPLEXITY = O(N^2)
    SPACE COMPLEXITY = O(N^2)
*/


class Solution {
   private:
   int height(Node* root){
       
       if(root == NULL)
            return 0;
            
        int h1 = height(root->left);
        int h2 = height(root->right);
        
        int ans = max(h1,h2)+1;
        return ans;
   }
   
   
   public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        if(root == NULL)
            return 0;
        
        int opt1 = diameter(root->left);
        int opt2 = diameter(root->right);
        int opt3 = height(root->right)+1+height(root->left);
    
        int ans = max(opt1, max(opt2,opt3));
    
        return ans;
        
    }
};


/*  
APPROACH 2 BY NOT MAKING SEPEARATE FUNCTION FOR TO FIND HEIGHT OF TREE
        TIME COPLEXITY    O(N)
        SPACE COMPLEXITY  O(N)
*/

