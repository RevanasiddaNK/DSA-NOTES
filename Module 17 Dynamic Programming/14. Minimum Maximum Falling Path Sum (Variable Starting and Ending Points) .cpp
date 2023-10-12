#include <bits/stdc++.h> 

// Recursion
int solveRec(vector<vector<int>> &matrix, int i, int j){
// Boundary Exceed Base Case
    if( j < 0 || j >= matrix[0].size() ){
        return -1e9;
    }
// Destination Base Case
    if(i==0)
        return matrix[0][j];

    int up = matrix[i][j] + solveRec(matrix,i-1,j);
    int diagLeft = matrix[i][j] + solveRec(matrix,i-1,j-1);
    int diagRight = matrix[i][j] + solveRec(matrix,i-1,j+1);

    return max(up, max(diagLeft,diagRight));   
}

//  Memoization
int solveMem(vector<vector<int>> &matrix, int i, int j,vector<vector<int>>&dp){
// Boundary Exceed Base Case
    if( j < 0 || j >= matrix[0].size() ){
        return -1e9;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

// Destination Base Case
    if(i==0)
        return matrix[0][j];

    int up = matrix[i][j] + solveMem(matrix,i-1,j,dp);
    int diagLeft = matrix[i][j] + solveMem(matrix,i-1,j-1,dp);
    int diagRight = matrix[i][j] + solveMem(matrix,i-1,j+1,dp);

    return dp[i][j] = max(up, max(diagLeft,diagRight));   
}

// Tabulation
int solveTab(vector<vector<int>> &matrix, int m, int n){
    vector<vector<int>>dp(m,vector<int>(n,0));
    // Base Case
    for(int i=0; i<n; i++)
        dp[0][i] = matrix[0][i];
    
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){

            int up,diagRight,diagLeft;
            up = diagLeft = diagRight = matrix[i][j];
            up += dp[i-1][j];
    
            if(j > 0)
                diagLeft += dp[i-1][j-1];
            else
                diagLeft += -1e9;
            
            if(j+1 < n)
                diagRight += dp[i-1][j+1];
            else
                diagRight += -1e9;

            dp[i][j] = max(up, max(diagLeft, diagRight));

        }
    }
    int maxi = dp[m-1][0];
    for(int i=0; i<n; i++)
        maxi = max(maxi,dp[m-1][i]);
    return maxi;
}

int solveSpaceOpt(vector<vector<int>> &matrix, int m, int n){

    vector<int>prev(n,0);
    // Base Case
    for(int i=0; i<n; i++)
        prev[i] = matrix[0][i];
    
    for(int i=1; i<m; i++){
        vector<int>curr(n,0);
        for(int j=0; j<n; j++){

            int up,diagRight,diagLeft;
            up = diagLeft = diagRight = matrix[i][j];
            up += prev[j];
    
            if(j > 0)
                diagLeft += prev[j-1];
            else
                diagLeft += -1e9;
            
            if(j+1 < n)
                diagRight += prev[j+1];
            else
                diagRight += -1e9;

            curr[j] = max(up, max(diagLeft, diagRight));
        }
        prev = curr;
    }

    int maxi = prev[0];
    for(int i=0; i<n; i++)
        maxi = max(maxi,prev[i]);
        
    return maxi;

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
/*
//  Recursion
    int maxi = INT_MIN;
    int i=m-1;
    for(int j=0; j<n; j++){
        int temp = solveRec(matrix,i,j);
        maxi = max(maxi,temp);
    }
    return maxi;
*/

/*
//  Memoization
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int maxi = INT_MIN;
    int i=m-1;
    for(int j=0; j<n; j++){
        int temp = solveMem(matrix,i,j,dp);
        maxi = max(maxi,temp);
    }
    return maxi;
*/

/*
//  Tabulation
    return solveTab(matrix,m,n);
*/

//  Space Optimization
    return solveSpaceOpt(matrix,m,n);

}
