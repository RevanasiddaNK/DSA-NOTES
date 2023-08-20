class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        
        if(root == NULL)
            return ans;
        
        map<int , int > HDnValMapping;
        queue<pair<Node* , int> > q;
        
        q.push(make_pair(root, 0));
        
        while( ! q.empty()) {
            
            pair<Node* , int> temp = q.front();
            q.pop();
            
            Node* FrontNode = temp.first;
            int hd = temp.second;
            
            HDnValMapping[hd] = FrontNode->data;
            
            if(FrontNode->left)
                q.push(make_pair(FrontNode->left,hd-1));
                
            if(FrontNode->right)
                q.push(make_pair(FrontNode->right,hd+1));
        }
        
        for(auto i: HDnValMapping){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
