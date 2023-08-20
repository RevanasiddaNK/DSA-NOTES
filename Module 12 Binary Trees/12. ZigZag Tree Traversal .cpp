/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int>ans;
        
        if(root == NULL)
            return ans;
        
        queue<Node*>q;
        q.push(root);
        bool Left2Right = true;
        
        while(! q.empty()){
            
            int size = q.size();
            vector<int>temp(size);
            
            for(int i=0; i<size ; i++){
                
                Node* FrontElement = q.front();
                q.pop();
                
                int index = Left2Right ? i : size-i-1 ;
                temp[index] = FrontElement->data;
                
                if(FrontElement->left)
                    q.push(FrontElement->left);
                
                if(FrontElement->right)
                    q.push(FrontElement->right);
            }
            
            for(auto i : temp)
                ans.push_back(i);
            
            Left2Right = ! Left2Right;
        }
        
        return ans;
    }
};
