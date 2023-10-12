#include <bits/stdc++.h> 

// RECURSION
int solveRec(int i,int j,vector<vector<int>> &grid){
    if(i == 0 && j == 0)
        return grid[i][j];
    
    if(i<0 || j<0){
       // return INT_MAX;
        return 1e9;
    }
    
    int up = grid[i][j]+solveRec(i-1,j,grid);
    int left = grid[i][j]+solveRec(i,j-1,grid);

    return min(up,left);
}

//  MEMOIZATION
int solveMem(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
    if(i == 0 && j == 0)
        return grid[i][j];
    
    if(i<0 || j<0){
       // return INT_MAX;
        return 1e9;
    }

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = grid[i][j]+solveMem(i-1,j,grid,dp);
    int left = grid[i][j]+solveMem(i,j-1,grid,dp);

    return dp[i][j] = min(up,left);
}

//  TABULATION
int solveTab(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == 0 && j== 0){
                dp[i][j] = grid[i][j];
                continue;
            }
            else{
                int up = 0;
                if(i > 0)
                    up = grid[i][j]+dp[i-1][j];
                else
                    up = 1e9;
                int left = 0;
                if(j > 0)
                    left = grid[i][j]+dp[i][j-1];
                else
                    left = 1e9;

                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[m-1][n-1];
}

//  SPACE OPTIMIZATION
int solveSpaceOpt(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    //vector<vector<int>>dp(m,vector<int>(n,0));
    vector<int>prevRow(n,0);

    for(int i=0; i<m; i++){
        vector<int>currRow(n,0);
        for(int j=0; j<n; j++){
            if(i == 0 && j== 0){
                currRow[j] = grid[i][j];
                continue;
            }
            else{
                int up = 0;
                if(i > 0)
                    up = grid[i][j]+prevRow[j];
                else
                    up = 1e9;
                int left = 0;
                if(j > 0)
                    left = grid[i][j]+currRow[j-1];
                else
                    left = 1e9;

                currRow[j] = min(up,left);
            }
        }
        prevRow = currRow;
    }
    return prevRow[n-1];
}



int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

//    return solveRec(m-1,n-1,grid);
    vector<vector<int>>dp(m,vector<int>(n,-1));
//    return solveMem(m-1,n-1,grid,dp);
//    return solveTab(grid);

    return solveSpaceOpt(grid);

}
