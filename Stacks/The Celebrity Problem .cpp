class Solution 
{
    
    private:
    
    bool knows(vector<vector<int> >& M,int a,int b){
        if(M[a][b])
            return 1;
        else
            return 0;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>stack1;
        
        for(int i=0;i<n;i++){
            stack1.push(i);
        }
        
        while(stack1.size() > 1){
            
            int a = stack1.top();
            stack1.pop();
            
            int b = stack1.top();
            stack1.pop();
            
            if(knows(M,a,b)){
                stack1.push(b);
            }
            else
            {
                stack1.push(a);
            }
        }
        
        int ans = stack1.top();
        
    // CHECKING THE ANSWER
        int zeroCount = 0;
        int oneCount = 0;
        for(int i=0;i<n;i++){
            
            // row
            if(M[ans][i] == 0)
                zeroCount++;
            // Column
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(zeroCount == n && oneCount == n-1)
            return ans;
        else
            return -1;
    }
};
