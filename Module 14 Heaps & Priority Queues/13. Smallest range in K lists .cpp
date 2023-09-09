/*
Time Complexity : O(n * k *log k)
Auxilliary Space  : O(k)
*/

class Solution{
    
    public:
    
    class Node{ 
        
        public:
        
        int data;
        int row;
        int col;
            
        // constructor
        Node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
    };
    
    class compare{
        public:
        bool operator() (Node* a, Node* b){
            return a->data > b->data;
        }            
    };
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        
        pair<int, int>ans;
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare >minHeap;
        
        for(int i=0; i<k; i++){
            
            Node* temp = new Node(KSortedArray[i][0],i,0);
            mini = min(mini, KSortedArray[i][0]);
            maxi = max(maxi, KSortedArray[i][0]);
            minHeap.push(temp);
            
        }
        
        int start = mini;
        int end = maxi;
        
        while( !minHeap.empty() ){
            
            Node* front = minHeap.top();
            minHeap.pop();
// in each step maxi and mini covering allthe lists are updated

            //mini updating
            mini = front->data;
            
            // Range Updating
            if(end - start > maxi - mini) {
                start = mini;
                end = maxi;
            }
            
            if(front->col+1 < n){
                // Maxi updating
                maxi = max(maxi, KSortedArray[front->row][front->col+1]);
                
                Node* temp = new Node(KSortedArray[front->row][front->col+1], front->row, front->col+1 );
                minHeap.push(temp);
                
            }
            else
            {
                break;
            }
             
        } 
        
        ans = make_pair(start,end);
        return ans;
        
    }
};
