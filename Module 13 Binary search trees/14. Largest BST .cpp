/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    
    class info{
        public:
        int mini;
        int maxi;
        bool isBST;
        int size;
    };
    
    info solve(Node* root, int &maxSize) {
        
        if(root == NULL) 
            return {INT_MAX, INT_MIN, true, 0};
            
        info left = solve(root->left, maxSize);
        info right = solve(root->right, maxSize);
        
        info curr;
        curr.size = left.size + right.size + 1;
        curr.mini = min(root->data , left.mini);
        curr.maxi = max(root->data, right.maxi);
        
        if(left.isBST && right.isBST && (root->data < right.mini && root->data > left.maxi)) {
            curr.isBST = true;
        }
        else {
            curr.isBST = false;
        }
        
        if(curr.isBST){
            maxSize = max(maxSize, curr.size);
        }
            
        return curr;    
    }
    
    int largestBst(Node *root)
    {
        int maxSize = 0;
    	info ans = solve(root,maxSize);
    	return maxSize;
    }
};
