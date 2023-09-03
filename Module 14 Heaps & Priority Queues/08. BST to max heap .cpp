//Approach 1
/*
Special Max Heap = 
 Convert a given BST into a Special Max Heap with the condition that all the values 
 in the left subtree of a node should be less than all the values in the right subtree of the node.
 This condition is applied on all the nodes in the so converted Max Heap.
*/
// to do meet SPECIAL MAX HEAP PROPERTIES we have to go for POST Order and IN Order TraversalS




// APPROACH 2 General Max Heap Not Special Max Heap
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
