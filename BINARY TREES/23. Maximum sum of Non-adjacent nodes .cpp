//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    
    private:
    pair<int, int> solve(Node* root){
        
        if(root == NULL){
            pair<int, int>ans = make_pair(0,0);
            return ans;
        }
        
        pair<int, int> LeftAns = solve(root->left);
        pair<int, int> RightAns = solve(root->right);
        
        pair<int, int> ans;
        ans.first = max( (LeftAns.second + RightAns.second + root->data) , (LeftAns.first + RightAns.first) );
        ans.second = (LeftAns.first + RightAns.first);
        
        return ans;
    }

    public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
       return solve(root).first;
    }
};
