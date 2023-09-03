// APPROACH 1 , find out why this approach is wrong ? this is even wrong for general Min Heap
// input 8 4 12 2 6 10 14 1 3 5 7 9 11 13 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
// my  output 1 2 4 8 9 5 10 11 3 6 12 13 7 14 15 
// Desired Output 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 void Traversal(BinaryTreeNode* root, vector<int>&vect) {
        
        if(root == NULL)
            return;
        
        Traversal(root->left, vect);
        vect.push_back(root->data);
        Traversal(root->right, vect);
            
    }
    
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int>vect;
    Traversal(root,vect);
        
        int size = vect.size();
        int i=0;
        root->data = vect[i++];
        root->left = NULL;
        root->right = NULL;
        queue<BinaryTreeNode*>q;
        q.push(root);
        
        while(i < size ) ) {          
            BinaryTreeNode* Front = q.front();
            q.pop();
            
            Front->left = new BinaryTreeNode(vect[i++]);
            if(i < size)
                Front->right = new BinaryTreeNode(vect[i++]);
            
            q.push(Front->left);
            q.push(Front->right);
        } 
        return root;
}

// APPROACH 2 Code is accepted IT is for SPECIAL MIN Heap
void PreOrderTraversal(BinaryTreeNode* root, vector<int>&vect, int &i) {
     
        if(i >= vect.size() || root == NULL)
                return;

        // PREorder LNR
        root->data = vect[i++];
        PreOrderTraversal(root->left,vect,i);
        PreOrderTraversal(root->right,vect,i);
 }

 void InOrderTraversal(BinaryTreeNode* root, vector<int>&vect) {
        
        if(root == NULL)
            return;
        
        InOrderTraversal(root->left, vect);
        vect.push_back(root->data);
        InOrderTraversal(root->right, vect);
            
    }
    
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int>vect;
    InOrderTraversal(root,vect);

    int i=0;
    PreOrderTraversal(root,vect,i);    

    return root;
}
