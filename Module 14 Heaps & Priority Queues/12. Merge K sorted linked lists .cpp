/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    
    class compare {
        
        public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }

    };
    
    void Insert(Node* &Tail, int val){
        
        Node* temp = new Node(val);
        Tail->next = temp;
        //Tail = Tail->next;
        Tail = temp;
        
    }
    
    Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue< Node*, vector<Node*>, compare >minHeap;
        
        for(int i=0; i< K; i++)
            minHeap.push(arr[i]);
        
        Node* ans = new Node(-1);
        Node* Tail = ans;
        
        while(minHeap.size() > 0){
            
            Node* temp = minHeap.top();
            minHeap.pop();
            
            Insert(Tail,temp->data);
            
            
            if(temp->next)
                minHeap.push(temp->next);
        }
        return ans->next;
    }
};

