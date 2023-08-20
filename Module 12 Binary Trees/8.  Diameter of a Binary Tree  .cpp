/* 
TWO APPROACHES
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
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {

private:
    pair<int, int> FastDiameter(Node* root) {
        
        if(root == NULL){
          pair<int, int> p = make_pair(0,0);
          return p;
        }
        
        pair<int, int> left1 = FastDiameter(root->left);
        pair<int, int> right1 = FastDiameter(root->right);
        
        
        
        int opt1 = left1.first;
        int opt2 = right1.first;
        
        int opt3 = left1.second + right1.second +1;
    
        pair<int, int> ans;
        ans.first= max(opt1, max(opt2,opt3));
    //    ans.second = opt3;
        ans.second = max(left1.second , right1.second)+1;
    
        return ans;
        
    }

public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       
       return FastDiameter(root).first;
    }
};
