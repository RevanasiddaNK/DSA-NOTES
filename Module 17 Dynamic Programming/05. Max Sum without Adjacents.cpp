// Recursive Solution 
	int solveRec(int *nums,int n, int size){
        if(n >= size)
            return 0;
    
        int incl = solveRec(nums,n+2,size)+nums[n];
        int excl = solveRec(nums,n+1,size)+0;

        return max(incl,excl);
    }
	
	
	// Memoization + Recursion 
	int solveMem1(int *nums,int n, int size,int dp[]){
        if(n >= size)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
    
        int incl = solveMem1(nums,n+2,size,dp)+nums[n];
        int excl = solveMem1(nums,n+1,size,dp)+0;

        dp[n] = max(incl,excl);
        return dp[n];
    }
    
    int solveMem2(int *nums,int n, int size,int dp[]){
        if(n < 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
    
        int incl = solveMem2(nums,n-2,size,dp)+nums[n];
        int excl = solveMem2(nums,n-1,size,dp)+0;

        dp[n] = max(incl,excl);
        return dp[n];
    }
   
	int findMaxSum(int *arr, int n) {
	    
	    int ans = 0;
	    //Recursion 
//	    ans = solveRec(arr,0,n);
	    
	    // Memoization 
	    int dp[n+1];
	    for(int i=0; i<=n; i++)
	        dp[i] = -1;
	    
	    ans = solveMem1(arr,0,n,dp);
        //ans = solveMem2(arr,n-1,n,dp);

    
        return ans;

	}
