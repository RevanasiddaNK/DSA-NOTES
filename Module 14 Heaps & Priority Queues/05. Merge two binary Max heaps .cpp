class Solution{
    public:
    
     void heapify( vector<int>& ans, int index,  int size)  
     {
      
        int left = (2*index)+1;
        int right = (2*index)+2;
        
        if(left < size && ans[left] > ans[index]){
            swap(ans[left], ans[index]);
            heapify(ans,left,size);
        }
        
        if(right < size && ans[right] > ans[index]){
            swap(ans[right], ans[index]);
            heapify(ans,right,size);
        }
        
    }

    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int m, int n) {
        
                vector<int>ans;
               
                for(auto i : a) 
                    ans.push_back(i);
                    
                for(auto i : b)
                    ans.push_back(i);
               
                int size = ans.size();
                for(int i=size/2-1; i >=0 ; i--) 
                    heapify(ans, i, size);

                return ans;
                
    }
};
