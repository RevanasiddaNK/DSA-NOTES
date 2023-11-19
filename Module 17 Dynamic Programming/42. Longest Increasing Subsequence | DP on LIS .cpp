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


int longestIncreasingSubsequence(int arr[], int n)
{
    int prevInd = -1;
    int ind = 0;
    //return solveRec(ind,prevInd,arr,n);

    prevInd = 0;
    ind = 1;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solveMem(ind,prevInd,arr,n,dp);
}
