/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
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
            
            
// Returns an iterator to the element with key-value ‘g’ in the map if found, else returns the iterator to end
        if(HDnValMapping.find(hd) == HDnValMapping.end())
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
