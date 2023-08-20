
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                
        vector<long long>ans;
        deque<long long>dq;
        
        // creating for first k elements for REFERENCE Creating a window for first k elements
        //process first window
        for(int i=0 ; i<K ; i++){
            if(A[i] < 0)
                dq.push_back(i);
        }
        
         //push ans for FIRST window
        if(dq.size() > 0)
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
            
         //now process for remaining windows    
        for(int i=K; i <N ; i++){
            
            //first pop out of window element
            if(! dq.empty() && i - dq.front() >= K)
                    dq.pop_front();
             
            //then push current element if it is NEGATIVE       
            if(A[i] < 0)
                dq.push_back(i);
                
            // Insert  First negative integer in current window to the ANS vector
            if(dq.size() > 0)
                ans.push_back(A[dq.front()]);
            else
                ans.push_back(0);  
        }
        return ans;
            
 }
