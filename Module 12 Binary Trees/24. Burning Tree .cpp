class Solution {
  public:
  
    void NodeToParentMapping(Node* root, int target, Node* &TargetNode, map<Node*, Node*> &NodeToParent) {
        
        stack<Node*>s;
        s.push(root);
        
        while(! s.empty()) {
            
            Node* front = s.top();
            s.pop();
            
            if(front->data == target)
                TargetNode = front;
            
            if(front->left) {
                NodeToParent[front->left] = front;
                s.push(front->left);
            }
            
            if(front->right) {
                NodeToParent[front->right] = front;
                s.push(front->right);
            }
        }
        
    }
    
    void solve(Node* TargetNode, int &count, map<Node*, Node*> &NodeToParent) {
        
        // why queue is used here ? why not stack ?
        queue<Node*>s;
        s.push(TargetNode);
        
        map<Node*,bool>isVisited;
        isVisited[TargetNode] = 1;
        
        while(! s.empty()) {
            
            int n = s.size();
            bool isBurnt = 0;
            
            for(int i=0;i<n;i++){
                
            // QUEUE is used to maintain FIFO order bcz burning parent and its childs 
            // if the condition is  each Node burn in 1 second, if its used i will go for only Node wise then
            // we can use queue or stack anyone 
            
                Node* front = s.front();
                s.pop();
            
                if(front->left && !isVisited[front->left]) {
                    isVisited[front->left] = 1;
                    isBurnt = 1;
                    s.push(front->left);
                }
            
                if(front->right && !isVisited[front->right]) {
                    isVisited[front->right] = 1;
                    isBurnt = 1;
                    s.push(front->right);
                }
            
                Node* parent = NodeToParent[front];
                if(parent && !isVisited[parent] ) {
                    isVisited[parent] = 1;
                    isBurnt = 1;
                    s.push(parent);
                }
            }
            if(isBurnt == 1)
                count++;
        }
    }
  
    int minTime(Node* root, int target) 
    {
        Node* TargetNode = NULL;
        map<Node*, Node*>NodeToParent;
        NodeToParent[root] = NULL;
        int count = 0;
        NodeToParentMapping(root,target,TargetNode, NodeToParent);
        
        solve(TargetNode, count, NodeToParent);
        
        return count;
        
    }
};
