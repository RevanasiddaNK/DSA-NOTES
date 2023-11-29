#include <bits/stdc++.h> 

int solveRec(int i, int j, vector<int>&coins){

	if(i > j)
		return 0;
	
	int maxi = -1e9;
	for(int ind=i; ind <=j; ind++){
		int gain = coins[i-1]*coins[ind]*coins[j+1] +
					solveRec(i,ind-1,coins) +
					solveRec(ind+1,j,coins);
		maxi = max(maxi,gain);
	}
	return maxi;
}

int solveMem(int i, int j, vector<int>&coins,vector<vector<int>>&dp){

	if(i > j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];
	
	int maxi = -1e9;
	for(int ind=i; ind <=j; ind++){
		int gain = coins[i-1]*coins[ind]*coins[j+1] +
					solveMem(i,ind-1,coins,dp) +
					solveMem(ind+1,j,coins,dp);
		maxi = max(maxi,gain);
	}
	return dp[i][j] = maxi;
}

int solveTab(vector<int>&coins, int n){

	vector<vector<int>>dp(n+2,vector<int>(n+2,0));

	for(int i=n; i>=1; i--){
		for(int j=1; j<=n; j++){

			if(i>j)
				continue;

			int maxi = -1e9;
			for(int ind=i; ind <=j; ind++){
				int gain = coins[i-1]*coins[ind]*coins[j+1] +
					dp[i][ind-1] + dp[ind+1][j];
				maxi = max(maxi,gain);
			}
			dp[i][j] = maxi;
		}
	}
	return dp[1][n];
}

int maxCoins(vector<int>&a)
{
	int n = a.size();
	a.push_back(1);
	a.insert(a.begin(),1);

	return solveRec(1,n,a);

	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	return solveMem(1,n,a,dp);

	return solveTab(a,n);
}
