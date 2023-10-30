int solveRec(int index,int length, vector<int>&price){
	if(index == 0){
		return length*price[0];
	}
	
	int notpick = 0 + solveRec(index-1, length, price);
	int pick = -1e8;
	if((index+1) <= length)
		pick = price[index] + solveRec(index, length-(index+1), price);

	return max(notpick,pick);

}

int solveMem(int index,int length, vector<int>&price, vector<vector<int>>&dp ){

	if(index == 0)
		return length*price[0];

	if(dp[index][length] != -1)
		return dp[index][length];
	
	int notpick = 0 + solveMem(index-1, length, price, dp);
	int pick = -1e8;
	if((index+1) <= length)
		pick = price[index] + solveMem(index, length-(index+1), price, dp);

	return dp[index][length] = max(notpick,pick);

}

int solveTab(vector<int>&price, int n){
	vector<vector<int>>dp(n,vector<int>(n+1,-1e8));

	for(int length=0; length<=n; length++)
		dp[0][length] = length*price[0];
	
	for(int index=1; index<n; index++){
		for(int length=0; length<=n; length++){
			int notpick = 0 + dp[index-1][length]; 
			int pick = -1e8;
			if((index+1) <= length)
				pick = price[index] + dp[index][length-(index+1)];
			dp[index][length] = max(notpick,pick);
		}
	}
	return dp[n-1][n];
}

int solveSpaceOpt(vector<int>&price,int n){
	vector<int>prev(n+1,-1e8);

	for(int length=0; length<=n; length++)
		prev[length] = length*price[0];
	
	for(int index=1; index<n; index++){
		vector<int>curr(n+1,-1e8);
		for(int length=0; length<=n; length++){
			int notpick = 0 + prev[length]; 
			int pick = -1e8;
			if((index+1) <= length)
				pick = price[index] + curr[length-(index+1)];
			curr[length] = max(notpick,pick);
		}
		prev = curr;
	}
	return prev[n];
}






int cutRod(vector<int>&price, int n)
{
	//return solveRec(n-1,n,price);

	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return solveMem(n-1,n,price,dp);

	return solveTab(price,n);

	return solveSpaceOpt(price,n);
}
