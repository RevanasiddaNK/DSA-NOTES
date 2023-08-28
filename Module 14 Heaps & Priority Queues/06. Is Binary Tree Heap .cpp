class Solution {
  public:
  
  
     bool isHeap_(struct Node* tree) {
        
        if(tree == NULL)
            return true;
         
        else if(tree->left == NULL && tree->right)
                return false;
           
        else if(tree->left && tree->right) {
            
            int d = tree->data;
            int l = tree->left->data;
            int r = tree->right->data;
            
            if(d >= l && d >= r) {
                bool a = isHeap_(tree->left);
                bool b = isHeap_(tree->right);
                
                return a && b;
            }
            else
                return false;
    
        }
        
        else if(tree->left && tree->right == NULL) {
            
            int d = tree->data;
            int l = tree->left->data;
            
            if(d >= l)
               return isHeap_(tree->left);
           
            else
                return false;
            
        }
        else
            return true;
        
    }
    
    bool isCBT(Node* tree,int index, int size) {
        
        if(tree == NULL)
            return 1;
        
        if(index >= size)
            return 0;
            
        bool left = isCBT(tree->left, 2*index+1, size);
        bool right = isCBT(tree->right, 2*index+2, size);
        
        return left && right;
        
    }
    
    void SizeofBT(struct Node* tree, int &count) {
        
        if(tree == NULL)
            return ;
            
        SizeofBT(tree->left,count);
            count++;
        SizeofBT(tree->right,count);
        
        
    }
  
    bool isHeap(struct Node* tree) {
       
        int size = 0;
        SizeofBT(tree, size);
        
        if( isHeap_(tree) && isCBT(tree,0,size) )
           return 1;
        else
            return 0;

    }
};
