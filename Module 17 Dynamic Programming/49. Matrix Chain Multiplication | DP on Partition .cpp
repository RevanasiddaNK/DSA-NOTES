#include <bits/stdc++.h> 

int solveRec(vector<int> &arr, int i, int j){
    
    if(i == j)
        return 0;

    int mini = 1e9;
    for(int k=i; k<=j-1; k++){
        int step = arr[i-1]*arr[k]*arr[j] + solveRec(arr,i,k) + solveRec(arr,k+1,j);
        mini = min(mini,step);
    }
    return mini;

}

int solveMem(vector<int> &arr, int i, int j,vector<vector<int>>&dp){
    
    if(i == j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;
    for(int k=i; k<=j-1; k++){
        int step = arr[i-1]*arr[k]*arr[j] + solveMem(arr,i,k,dp) + solveMem(arr,k+1,j,dp);
        mini = min(mini,step);
    }
    return dp[i][j] = mini;

}

int solveTab(vector<int> &arr, int N){
    // step 1 
    vector<vector<int>>dp(N,vector<int>(N,0));

    //  step 2 : Base Case
    for(int i=0; i<N; i++)
        dp[i][i] = 0;
    
    //  step 3 : Changing parameters to nested loop TOP-DOWN Approach
    for(int i=N-1;i > 0; i--){
        for(int j=i+1; j<N; j++){
            //  step 4 : Copy recurence
            int mini = 1e9;
            for(int k=i; k<=j-1; k++){
                int step = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini,step);
            }   
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return solveRec(arr,1,N-1);

    vector<vector<int>>dp(N,vector<int>(N,-1));
    return solveMem(arr,1,N-1,dp);

    return solveTab(arr,N);

}
