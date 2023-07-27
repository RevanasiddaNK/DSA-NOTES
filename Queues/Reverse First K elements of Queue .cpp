TWO APPROACHES


APPROACH 1 
TIME COMPLEXIRTY O(N) AND SPACE COMPLEXITY O(K)
// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {  
    stack<int>ans;
    for(int i =0 ; i<k ; i++){
        ans.push(q.front());
        q.pop();
    }
    while( !ans.empty() ){
        q.push(ans.top());
        ans.pop();
    }
   int n = q.size();
   for(int i=0 ; i < n - k  ; i++){
        q.push(q.front());
        q.pop();
    }  
    return q;               
}




APPROACH 2
RECURSIVE SOLUTION
WITH TIME COMPLEXIRTY O(N) AND SPACE COMPLEXITY O(N)
void ReverseK(queue<int>&q, int k){
    
    if(q.size() == 0 || q.size() == 1)
        return;
        
    int element = q.front();
    q.pop();
   
    ReverseK(q,k);
    
    q.push(element);
    
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    queue<int>ans;
    for(int i =0 ; i<k && q.size() > 0 ; i++){
        ans.push(q.front());
        q.pop();
    }
    ReverseK(ans,k);
    while(q.size() != 0){
        ans.push(q.front());
        q.pop();
    }  
    return ans;              
}
