
int solveTab(vector<int>&arr, int n, int totalsum){
    
    vector<vector<bool>>dp(n,vector<bool>(totalsum/2+1));
    
    // Base Case
    for(int i=0; i<n; i++)
        dp[i][0] = 1;
    
    if(arr[0] <= totalsum/2 )
        dp[0][arr[0]] = 1;
    
    for(int index=1; index<n; index++){
        for(int target = 1; target <= totalsum/2; target++){
            
            bool nottake = dp[index-1][target];
            bool take = false;
            if(arr[index] <= target)
                take = dp[index-1][target-arr[index]];
                
            dp[index][target] = nottake || take;

        }
    }
    
    int mini = 1e9;
    for(int i=0; i<= totalsum/2; i++){
        if(dp[n-1][i] == true){
            int s1 = i;
            int s2 = totalsum-s1;
            mini = min(mini, abs(s1-s2));
        }
    }
    return mini;   
}

int solveSpaceOpt(vector<int>&arr, int n, int totalsum){
    
    vector<bool>prev(totalsum/2+1,false);  
    // Base Case
    for(int i=0; i<n; i++)
        prev[0] = 1;
          
    if(arr[0] <= totalsum/2 )
        prev[arr[0]] = 1;
    
    for(int index=1; index<n; index++){
        vector<bool>curr(totalsum/2+1,false);
        curr[0] = true;
        for(int target = 1; target <= totalsum/2; target++){         
            bool nottake = prev[target];
            bool take = false;
            if(arr[index] <= target)
                take = prev[target-arr[index]];                
            curr[target] = nottake || take;
        }
        prev = curr;
    }   
    int mini = 1e9;
    for(int i=0; i<= totalsum/2; i++){
        if(prev[i] == true){
            int s1 = i;
            int s2 = totalsum-s1;
            mini = min(mini, abs(s1-s2));
        }
    }
    return mini;   
}

int minSubsetSumDifference(vector<int>&arr, int n)
{
    int totalsum = 0;
    for(int i=0; i<n; i++)
        totalsum += arr[i];
        
    return solveTab(arr,n,totalsum);
    return solveSpaceOpt(arr,n,totalsum);
}
