#include<bits/stdc++.h>

int solveRec(int ind, int prevInd, int arr[], int n){
    if(ind == n)
        return 0;
    
    int notTake = 0 + solveRec(ind+1,prevInd,arr,n);
    int take = 0;
    if(prevInd == -1 || arr[prevInd] < arr[ind])
        take = 1 + solveRec(ind+1,ind,arr,n);

    return max(take,notTake);
}

int solveMem(int ind, int prevInd, int arr[], int n,vector<vector<int>>&dp){

    if(ind == n)
        return 0;

    if(dp[ind][prevInd+1] != -1)
        return dp[ind][prevInd+1];
    
    int notTake = 0 + solveMem(ind+1,prevInd,arr,n,dp);
    int take = 0;
    if(prevInd == -1 || arr[prevInd] < arr[ind])
        take = 1 + solveMem(ind+1,ind,arr,n,dp);

    return dp[ind][prevInd+1] = max(take,notTake);
}

int solveTab(int arr[], int n){

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(int prevInd=0; prevInd<n+1; prevInd++)
        dp[n][prevInd] = 0;

    for(int ind = n-1; ind>=0; ind--){
        for(int prevInd = ind-1; prevInd >= -1; prevInd--){

            int notTake = 0 + dp[ind+1][prevInd+1];
            int take = 0;
            if(prevInd == -1 || arr[prevInd] < arr[ind])
                take = 1 + dp[ind+1][ind+1];

            dp[ind][prevInd+1] = max(take,notTake);
        }
    }
    return dp[0][-1+1];
}

int solveSpaceOpt(int arr[], int n){

    vector<int>prev(n+1,-1);
    for(int prevInd=0; prevInd<n+1; prevInd++)
        prev[prevInd] = 0;

    for(int ind = n-1; ind>=0; ind--){
        vector<int>curr(n+1,-1);
        for(int prevInd = ind-1; prevInd >= -1; prevInd--){

            int notTake = 0 + prev[prevInd+1];
            int take = 0;
            if(prevInd == -1 || arr[prevInd] < arr[ind])
                take = 1 + prev[ind+1];

            curr[prevInd+1] = max(take,notTake);
        }
        prev = curr;
    }
    return prev[-1+1];
}

int solveSpaceOpt2(int arr[], int n){

    vector<int>dp(n+1,-1);
    for(int prevInd=0; prevInd<n+1; prevInd++)
        dp[prevInd] = 0;

    for(int ind = n-1; ind>=0; ind--){
        for(int prevInd = ind-1; prevInd >= -1; prevInd--){

            int notTake = 0 + dp[prevInd+1];
            int take = 0;
            if(prevInd == -1 || arr[prevInd] < arr[ind])
                take = 1 + dp[ind+1];

            dp[prevInd+1] = max(take,notTake);
        }
    }
    return dp[-1+1];
}

int solveTraceBack(int arr[], int n){

    vector<int>dp(n,1);

    int maxi = 0;
    for(int ind=0; ind<n; ind++){
        for(int pre=0; pre<ind; pre++){
            if(arr[ind] > arr[pre] && dp[ind] < 1+dp[pre]){
                dp[ind] = 1 + dp[pre];
            }
        }
        maxi = max(maxi,dp[ind]);
    }
    return maxi;
}


int longestIncreasingSubsequence(int arr[], int n)
{
    int prevInd = -1;
    int ind = 0;
    return solveRec(ind,prevInd,arr,n);

    prevInd = -1;
    ind = 0;
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return solveMem(ind,prevInd,arr,n,dp);

    return solveTab(arr,n); 
    return solveSpaceOpt(arr,n);
    return solveSpaceOpt2(arr,n);

    return solveTraceBack(arr,n);
}
