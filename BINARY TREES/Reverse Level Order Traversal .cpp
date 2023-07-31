/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

vector<int> reverseLevelOrder(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    stack<int>s;
   
    q.push(root);
   
    while( ! q.empty()) {
        
       Node* temp = q.front();
       s.push(temp->data);
       q.pop();
       
        if(temp->right)
            q.push(temp->right);
           
        if(temp->left)
            q.push(temp->left);
   }
   
   while(! s.empty()) {
       ans.push_back(s.top());
       s.pop();
   }
   
   return ans;
}
