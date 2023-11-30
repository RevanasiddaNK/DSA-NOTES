class Node{
  public:
  int data;
  Node* left;
  Node* right;
  
  Node(int d){
      data = d;
      left = NULL;
      right = NULL;
  }
};

class comp{
    public:
  bool operator()(Node* a, Node*b){
      return a->data > b->data;
  }  
};

class Solution
{
	public:
	
	    void preOrderTraversal(Node* root,vector<string>&ans,string temp ){
	        
	        if(root->right == NULL && root->left == NULL){
	            ans.push_back(temp);
	            return;
	        }
	        
	        if(root->left){
	            preOrderTraversal(root->left,ans,temp+'0');
	        }
	        
	        if(root->right){
	            preOrderTraversal(root->right,ans,temp+'1');
	        }
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Create a HuffMan Tree using priority_queue
		    priority_queue<Node*,vector<Node*>,comp>pq;
		    
		    for(int i=0; i<N; i++){
		        Node* temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size() > 1){
		        
		        Node* first = pq.top();
		        pq.pop();
		        
		        Node* second = pq.top();
		        pq.pop();
		        
		        int NewData = (first->data + second->data);
		        Node* NewNode = new Node(NewData);
		        
		        NewNode->left = first;
		        NewNode->right = second;
	 
	            pq.push(NewNode);
		    }
		    
		    Node* root = pq.top();
		    vector<string>ans;
		    string temp = "";
		    preOrderTraversal(root,ans,temp);
		    return ans;
		}
};
