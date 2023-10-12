#include <bits/stdc++.h>

//	Recursion
int solveRec(int i, int j, vector<vector<int>>&triangle, int m){

	// Base Case
	if(i == m-1)
		return triangle[m-1][j];

	// why boundary base cases are not required here?

	// explore all paths movements down, right downward movement
	int down = triangle[i][j] + solveRec(i+1,j,triangle,m);
	int diag = triangle[i][j] + solveRec(i+1,j+1,triangle,m);

	return min(down,diag);
}

//	Memoization
int solveMem(int i, int j, vector<vector<int>>&triangle, int m,vector<vector<int>>&dp){

	// Base Case
	if(i == m-1)
		return triangle[m-1][j];

	if(i < m && j < m){
		if(dp[i][j] != -1)
			return dp[i][j];
	}

	// why boundary base cases are not required here?

	// explore all paths movements down, right downward movement
	int down = triangle[i][j] + solveMem(i+1,j,triangle,m,dp);
	int diag = triangle[i][j] + solveMem(i+1,j+1,triangle,m,dp);

	return dp[i][j] = min(down,diag);
}

//	Tabulation
int solveTab(vector<vector<int>>& triangle, int m){
	vector<vector<int>>dp(m,vector<int>(m,0));
	// Base Cases
	for(int i=0; i<m; i++)
		dp[m-1][i] = triangle[m-1][i];
	
	for(int i=m-2; i>=0; i--){
		for(int j=i; j>=0; j--){
			int down = triangle[i][j] + dp[i+1][j];
			int diag = triangle[i][j] + dp[i+1][j+1];
			dp[i][j] = min(down,diag);
		}
	}
	return dp[0][0];
}

// Space Optimization
int solveSpaceOpt(vector<vector<int>>& triangle, int n){
	vector<int>front(n,0);
	// Base Cases
	for(int i=0; i<n; i++)
		front[i] = triangle[n-1][i];
	
	for(int i=n-2; i>=0; i--){
		vector<int>curr(n,0);
		for(int j=i; j>=0; j--){
			int down = triangle[i][j] + front[j];
			int diag = triangle[i][j] + front[j+1];
			curr[j] = min(down,diag);
		}
		front = curr;
	}
	return front[0];
}


int minimumPathSum(vector<vector<int>>& triangle, int m){
	int i=0,j=0;
//	return solveRec(i,j,triangle,m);
	vector<vector<int>>dp(m,vector<int>(m,-1));
//	return solveMem(i,j,triangle,m,dp);
//	return solveTab(triangle,m);
	return solveSpaceOpt(triangle,m);

}
