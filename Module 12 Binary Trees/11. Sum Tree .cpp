/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    pair<bool, int> SumTree(Node* root){
        
        if(root == NULL){
            pair<bool, int>ans = make_pair(true, 0);
            return ans;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool,int>ans = make_pair(true, root->data);
            return ans;
        }
        
        pair<bool, int>left = SumTree(root->left);
        pair<bool, int>right = SumTree(root->right);
        
        bool checkVal = root->data == (left.second + right.second);
        
        pair<bool, int> ans;
        if(left.first && right.first && checkVal){
            ans.first = true;
        //    ans.second = 2 * (root->data);
            ans.second = root->data + (left.second + right.second) ;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    
    public:
    bool isSumTree(Node* root)
    {
        return SumTree(root).first;
    }
};
