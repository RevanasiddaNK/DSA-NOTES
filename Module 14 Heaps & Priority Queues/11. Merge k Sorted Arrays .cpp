class Solution
{
    public:
    
    class Node
    {
        public:
        
            int data;
            int row;
            int col;
        
        Node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }  
        
    };
    
    class compare
    {
        public:
        
        bool operator() (Node* a, Node*b) {
            return a->data > b->data;
        } 
    };
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*, vector<Node*>, compare >minHeap;
        
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            Node* temp = new Node(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        while(minHeap.size() > 0) {
            
            Node* temp1 = minHeap.top();
            minHeap.pop();
            
            int data = temp1->data;
            int row = temp1->row;
            int col = temp1->col;
            
            ans.push_back(data);
            
           if(row < arr.size() && col+1 < arr[row].size()){
                Node* temp2 = new Node(arr[row][col+1],row,col+1);
                minHeap.push(temp2);
            }
        }
        
        return ans;
    }
};
