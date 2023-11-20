#include<bits/stdc++.h>

int solveRec(int ind, int prevInd, int arr[], int n){
    if(ind >= n)
        return 0;
    
    int notTake = 0 + solveRec(ind+1,prevInd,arr,n);
    int take = 0;
    if(prevInd == -1 || arr[prevInd] < arr[ind])
        take = 1 + solveRec(ind+1,ind,arr,n);

    return max(take,notTake);
}

int solveMem(int ind, int prevInd, int arr[], int n,vector<vector<int>>&dp){

    if(ind == n+1)
        return 0;

    if(dp[ind][prevInd] != -1)
        return dp[ind][prevInd];
    
    int notTake = 0 + solveMem(ind+1,prevInd,arr,n,dp);
    int take = 0;
    if(prevInd == 0 || arr[prevInd-1] < arr[ind-1])
        take = 1 + solveMem(ind+1,ind,arr,n,dp);

    return dp[ind][prevInd] = max(take,notTake);
}

int solveTab(int arr[], int n){
    vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
    //Base Case
    for(int prevInd=n+1; prevInd >=0; prevInd--)
        dp[n+1][prevInd] = 0;
    
    // changing parameters nested for loops 
    for(int ind = n; ind>=1; ind--){
        for(int prevInd= ind-1; prevInd >= 0; prevInd--){
            int notTake = 0 + dp[ind+1][prevInd];
            int take = 0;
            if(prevInd == 0 || arr[prevInd-1] < arr[ind-1] )
                take = 1 + dp[ind+1][ind];

            dp[ind][prevInd] = max(take,notTake);
        }
    }
    return dp[1][0];
}

int solveSpaceOpt(int arr[], int n){
    vector<int>prev(n+1,-1);
    //Base Case
    for(int prevInd=n; prevInd >=0; prevInd--)
        prev[prevInd] = 0;
    
    // changing parameters nested for loops 
    for(int ind = n; ind>=1; ind--){
        vector<int>curr(n+1,-1);
        for(int prevInd= ind-1; prevInd >= 0; prevInd--){
            int notTake = 0 + prev[prevInd];
            int take = 0;
            if(prevInd == 0 || arr[prevInd-1] < arr[ind-1] )
                take = 1 + prev[ind];

            curr[prevInd] = max(take,notTake);
        }
        prev = curr;
    }
    return prev[0];
}

int longestIncreasingSubsequence(int arr[], int n)
{
    int prevInd = -1;
    int ind = 0;
    return solveRec(ind,prevInd,arr,n);

    prevInd = 0;
    ind = 1;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solveMem(ind,prevInd,arr,n,dp);

    return solveTab(arr,n);

    return solveSpaceOpt(arr,n);
}
