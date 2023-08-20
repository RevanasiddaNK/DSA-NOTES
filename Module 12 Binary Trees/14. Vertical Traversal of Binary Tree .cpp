class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int>ans;
        
        if(root == NULL)
            return ans;
            
        map<int, map<int, vector<int> > >NodeMap;
        queue<pair<Node* , pair<int, int > > >q;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(! q.empty()) {
            pair<Node*,pair<int, int >>temp = q.front();
            q.pop();
            // hd horizontal distance
            int hd = temp.second.first;
            int level = temp.second.second;
            Node* FrontNode = temp.first;
            
            NodeMap[hd][level].push_back(FrontNode->data);
            
            if(FrontNode->left)
                    q.push(make_pair(FrontNode->left, make_pair(hd-1, level+1)));
                    
            if(FrontNode->right)
                    q.push(make_pair(FrontNode->right, make_pair(hd+1, level+1)));
            
        }
        
        for(auto i : NodeMap ){
            for(auto j : i.second){
                for(auto k : j.second ){
                    ans.push_back(k);
                }
            }
        }
        
        return ans;
    }
};
