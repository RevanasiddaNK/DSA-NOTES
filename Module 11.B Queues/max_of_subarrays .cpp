

    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
        vector<int>ans;
        deque<int>maxi(k);
       
        for(int i=0 ; i<k ; i++){
            while(!maxi.empty() && arr[maxi.back()] <= arr[i])
                maxi.pop_back();
            maxi.push_back(i);
        }
        ans.push_back(arr[maxi.front()]);
        
        for(int i=k ; i < n ; i++){
            while( ! maxi.empty() && i - maxi.front() >= k)
                maxi.pop_front();
        
           while(!maxi.empty() && arr[maxi.back()] <= arr[i])
                maxi.pop_back();
                
            maxi.push_back(i);
            ans.push_back(arr[maxi.front()]);
        }   
        return ans;
    }
