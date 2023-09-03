



// APPROACH 2 General Max Heap Not Special 
class Solution{
  public:
    
    void Traversal(Node* root, vector<int>&vect) {
        
        if(root == NULL)
            return;
        
        Traversal(root->left, vect);
        vect.push_back(root->data);
        Traversal(root->right, vect);
            
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int>vect;
        Traversal(root,vect);
    //reverse(vect.begin(), vect.end());
        
        int size = vect.size();
        int i=size-1;
        root->data = vect[i--];
        root->left = NULL;
        root->right = NULL;
        queue<Node*>q;
        q.push(root);
        
        while(i >= 0 ) {          
            Node* Front = q.front();
            q.pop();
            
            Front->left = newNode(vect[i--]);
            if(i >= 0)
                Front->right = newNode(vect[i--]);
            
            q.push(Front->left);
            q.push(Front->right);
        } 
    }    
};
