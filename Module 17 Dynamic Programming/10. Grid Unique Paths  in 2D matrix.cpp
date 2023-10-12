#include <bits/stdc++.h> 
//Recursion Top Down
int solveRec(int i, int j){
    // Base Case
    if(i == 0 && j == 0)
        return 1;

    //Boundary Edge cases
    if(i<0 || j<0)
        return 0;

    int up = solveRec(i-1,j);
    int left = solveRec(i,j-1);

    return up+left;
}

// Memoization
int solveMem(int i, int j, vector<vector<int>>&dp){

    // Base Case
    if(i == 0 && j == 0)
        return 1;

    //Boundary Edge cases
    if(i<0 || j<0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int up = solveMem(i-1,j,dp);
    int left = solveMem(i,j-1,dp);

    return dp[i][j] = up+left;
}

// Tabulation bottom Up
int solveTab(int m,int n){
    vector<vector<int>>dp(m,vector<int>(n,0));
    // Bottom Up Aproach
    //base case
    dp[0][0] = 1;

    // for loops by analysing recursive calls
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int left=0,up=0;
            // Base Case 
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }

            if(i > 0)
                up = dp[i-1][j];
            if(j > 0)
                left = dp[i][j-1];

            dp[i][j] = up+left;
        }
    }
    return dp[m-1][n-1];
}

int solveSpaceOpt(int m, int n){
    vector<int>prevRow(n,0);
    // Bottom Up Aproach
    // base case
    // prevRow[0] = 1;

    // for loops by analysing recursive calls
    for(int i=0; i<m; i++){
        vector<int>curr(n,0);
        for(int j=0; j<n; j++){

            int left=0,up=0;
            // Base Case 
            if(i == 0 && j == 0){
                //dp[i][j] = 1;
                curr[j] = 1;
                continue;
            }
            if(i != 0){
                // up = dp[i-1][j];
                up = prevRow[j];
            }
            if(j != 0){
               // left = dp[i][j-1];
                left = curr[j-1];
            }
            // dp[i][j] = up+left;
            curr[j] = up+left;

        }
        prevRow = curr;
    }
    // return dp[m-1][n-1];
    return prevRow[n-1];
}

int uniquePaths(int m, int n){

//    return solveRec(m-1,n-1);
    vector<vector<int>>dp(m,vector<int>(n,-1));
//    return solveMem(m-1,n-1,dp);
//    return solveTab(m,n);
    return solveSpaceOpt(m,n);
}
	
