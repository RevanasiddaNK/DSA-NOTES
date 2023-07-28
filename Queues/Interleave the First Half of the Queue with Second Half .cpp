
//  TWO METHODS

//      1.  FIRST METHOD
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

//       2. SECOND METHOD

