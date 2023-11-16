#include<bits/stdc++.h>

int solveRec( int i,vector<int>&prices,int n,int transInd, int k)
{
    if(transInd == 2*k || i == n)
        return 0;
    
    if(transInd%2 == 0)
        return max( (-prices[i]+solveRec(i+1,prices,n,transInd+1,k)) , solveRec(i+1,prices,n,transInd,k) );
    else
        return max( (prices[i]+solveRec(i+1,prices,n,transInd+1,k)) , solveRec(i+1,prices,n,transInd,k) );
}

int solveMem(int i,vector<int>&prices,int n,int transInd,vector<vector<int>>&dp,int k)
{
    if(transInd == 2*k || i == n)
        return 0;

    if(dp[i][transInd] != -1)
        return dp[i][transInd];
    
    if(transInd%2 == 0)
        return dp[i][transInd] = max( (-prices[i]+ solveMem(i+1,prices,n,transInd+1,dp,k)) ,solveMem(i+1,prices,n,transInd,dp,k) );
    else
        return dp[i][transInd] =  max( (prices[i]+ solveMem(i+1,prices,n,transInd+1,dp,k)) , solveMem(i+1,prices,n,transInd,dp,k) );
}

int solveTab(vector<int>&prices, int n,int k)
{
    vector<vector<int>>dp(n+1,vector<int>( (2*k)+1,-1));

    // Base Cases
    for(int i=0; i<=n; i++)
        dp[i][2*k] = 0;
    
    for(int transInd=0; transInd <= 2*k; transInd++)
        dp[n][transInd] = 0;

    for(int i=n-1; i >= 0; i--){
        for(int transInd=0; transInd < 2*k; transInd++){
            if(transInd%2 == 0)
                dp[i][transInd] = max( (-prices[i]+ dp[i+1][transInd+1]) ,dp[i+1][transInd] );
            else
                dp[i][transInd] =  max( (prices[i]+ dp[i+1][transInd+1]) , dp[i+1][transInd] );

        }
    }
    return dp[0][0];
}

int solveSpaceOpt(vector<int>&prices, int n,int k)
{
    vector<int>prev(2*k+1,-1);
    // Base Cases  
    for(int transInd=0; transInd < 2*k+1; transInd++)
        prev[transInd] = 0;

    for(int i=n-1; i >= 0; i--){
        vector<int>curr(2*k+1,-1);
        curr[2*k] = 0;
        for(int transInd=0; transInd < 2*k; transInd++){
            if(transInd%2 == 0)
                curr[transInd] = max( (-prices[i]+ prev[transInd+1]) ,prev[transInd] );
            else
                curr[transInd] =  max( (prices[i]+ prev[transInd+1]) , prev[transInd] );

        }
        prev = curr;
    }
    return prev[0];
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    int transInd = 0;
    
    return solveRec(0,prices,n,transInd,k);

    vector<vector<int>>dp(n,vector<int>(2*k,-1));
    return solveMem(0,prices,n,transInd,dp,k);

    return solveTab(prices,n,k);

    return solveSpaceOpt(prices,n,k);
}
