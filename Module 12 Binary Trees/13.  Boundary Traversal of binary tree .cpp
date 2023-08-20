/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {

private:
    void LeftTraversal(Node* root , vector<int>&ans){
        
        if(root == NULL || (root->left == NULL && root->right == NULL))
                    return ;
        
        ans.push_back(root->data);
        
        if(root->left)
            LeftTraversal(root->left, ans);
        else
            LeftTraversal(root->right, ans);
    }

    void LeafNodeTraversal( Node* root, vector<int>&ans)  {
        
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)   {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left)
            LeafNodeTraversal(root->left, ans);
        
        if(root->right)
            LeafNodeTraversal(root->right, ans);
            
    }
    
    void RightTraversal(Node* root , vector<int>&ans){
        
        if(root == NULL || (root->left == NULL && root->right == NULL))
                    return ;
        
        if(root->right)
            RightTraversal(root->right, ans);
        else
            RightTraversal(root->left, ans);
            
        ans.push_back(root->data);
        
    }


public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        
        if(root == NULL)
            return ans;
        
        ans.push_back(root->data);
        
        // Step 1 Left Traversal
        LeftTraversal(root->left, ans);
        
        // Step 2 Leaf Nodes Traversal
        
        // why not single pass ? bcz main root node will be included if binary tree has single node
        LeafNodeTraversal(root->left, ans);
        LeafNodeTraversal(root->right, ans);
        
        // Step 3 Right Traversal
        RightTraversal(root->right, ans);
        
        return ans;
    }
};
