// #define modulo 1e9
int modulo = 1e9+7;

// Recursion
int solveRec(int index, vector<int>&arr, int sum){

	if(sum == 0)
		return 1;

	if(index == 0)
		return arr[0] == sum;


    //not pick
	int unpick = solveRec(index-1, arr, sum);

    // pick
	int pick = 0;
	if(arr[index] <= sum)
		pick = solveRec(index-1, arr, sum-arr[index]);
    
    return (unpick+pick)%modulo;

}

// Memoization
int solveMemoization(int index, vector<int>&arr, int sum, vector<vector<int>>&dp){

	if(sum == 0)
		return dp[index][sum] = 1;

	if(index == 0)
		return dp[index][sum] = arr[0] == sum;

	if(dp[index][sum] != -1)
		return dp[index][sum];

    //not pick
	int unpick = solveMemoization(index-1,arr,sum,dp);

    // pick
	int pick = 0;
	if(arr[index] <= sum)
		pick = solveMemoization(index-1,arr,sum-arr[index],dp);
    
    return dp[index][sum] = (unpick+pick)%modulo;

}

//	Tabulation
int solveTabulation(vector<int>&arr , int k, int n){
	// step 1 -> base cases
	vector<vector<int>>dp(n,vector<int>(k+1,0));
	
	for(int i=0; i<n; i++)
		dp[i][0] = 1;

	if(arr[0] <= k)
		dp[0][arr[0]] = 1;

	// step 2 -> nested loops
	for(int index=1; index<n; index++){
		for(int sum=0; sum<=k; sum++){
			// step 2 -> copy Recursion
			int unpick = dp[index-1][sum];
			int pick = 0;
			if(arr[index] <= sum)
				pick = dp[index-1][sum-arr[index]];

			dp[index][sum] = (unpick+pick)%modulo;	
		}
	}
	return dp[n-1][k];
}

//	Space Optimization
int solveSpaceOpt(vector<int>&arr , int k, int n){
	// step 1 -> base cases
	vector<int>prev(k+1,0);
	
	for(int i=0; i<n; i++)
		prev[0] = 1;

	if(arr[0] <= k)
		prev[arr[0]] = 1;

	// step 2 -> nested loops
	for(int index=1; index<n; index++){
		vector<int>curr(k+1,0);
		for(int sum=0; sum<=k; sum++){
			// step 2 -> copy Recursion
			int unpick = prev[sum];
			int pick = 0;
			if(arr[index] <= sum)
				pick = prev[sum-arr[index]];

			curr[sum] = (unpick+pick)%modulo;	
		}
		prev = curr;
	}
	return prev[k];
}





int findWays(vector<int>&arr , int k)
{
	int n = arr.size();
	return solveRec(n-1,arr,k);
	
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return solveMemoization(n-1,arr,k,dp);

	return solveTabulation(arr,k,n);

	return solveSpaceOpt(arr,k,n);
}
