//  TWO METHODS

//      1.  FIRST METHOD
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
            int n = q.size();
            vector<int>ans;
            stack<int>s;
            int m = n/2;
            
            //  first
            for(int i=0 ; i<m ; i++) {
                s.push(q.front());
                q.pop();
            }
            
            while(! s.empty()) {
                q.push(s.top());
                s.pop();
            }
          
            //  second
            for(int i=0 ; i<m ; i++) {
                q.push(q.front());
                q.pop();
            }
            
            for(int i=0; i <m ; i++){
                s.push(q.front());
                q.pop();
            }
  
            // creating an answer array
            while(! s.empty())  {
                
                ans.push_back(s.top());
                s.pop();
                
                ans.push_back(q.front());
                q.pop();
            }
            
            return ans;
    }
};


//       2. SECOND METHOD
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
            int n = q.size();
            vector<int>ans;
            queue<int>q1;
            int m = n/2;
            
            for(int i=0 ; i<m ; i++) {
                q1.push(q.front());
                q.pop();
            }
            
            while(! q.empty()){
                ans.push_back(q1.front());
                ans.push_back(q.front());
                q.pop();
                q1.pop();
            }
            
            return ans;
    }
};
