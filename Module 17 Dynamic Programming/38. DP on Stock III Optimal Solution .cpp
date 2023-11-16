#include<bits/stdc++.h>

int solveRec( int i,vector<int>&prices,int n,int transInd)
{
    if(transInd == 4 || i == n)
        return 0;
    
    if(transInd%2 == 0)
        return max( (-prices[i]+solveRec(i+1,prices,n,transInd+1)) , solveRec(i+1,prices,n,transInd) );
    else
        return max( (prices[i]+solveRec(i+1,prices,n,transInd+1)) , solveRec(i+1,prices,n,transInd) );
}

int solveMem(int i,vector<int>&prices,int n,int transInd,vector<vector<int>>&dp)
{
    if(transInd == 4 || i == n)
        return 0;

    if(dp[i][transInd] != -1)
        return dp[i][transInd];
    
    if(transInd%2 == 0)
        return dp[i][transInd] = max( (-prices[i]+ solveMem(i+1,prices,n,transInd+1,dp)) ,solveMem(i+1,prices,n,transInd,dp) );
    else
        return dp[i][transInd] =  max( (prices[i]+ solveMem(i+1,prices,n,transInd+1,dp)) , solveMem(i+1,prices,n,transInd,dp) );
}

int solveTab(vector<int>&prices, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(5,-1));

    // Base Cases
    for(int i=0; i<n; i++)
        dp[i][4] = 0;
    
    for(int transInd=0; transInd <5; transInd++)
        dp[n][transInd] = 0;

    for(int i=n-1; i >= 0; i--){
        for(int transInd=0; transInd <5; transInd++){
            if(transInd%2 == 0)
                dp[i][transInd] = max( (-prices[i]+ dp[i+1][transInd+1]) ,dp[i+1][transInd] );
            else
                dp[i][transInd] =  max( (prices[i]+ dp[i+1][transInd+1]) , dp[i+1][transInd] );

        }
    }
    return dp[0][0];
}

int solveSpaceOpt(vector<int>&prices, int n)
{
    vector<int>prev(5,-1);
    // Base Cases  
    for(int transInd=0; transInd <5; transInd++)
        prev[transInd] = 0;

    for(int i=n-1; i >= 0; i--){
        vector<int>curr(5,-1);
        curr[4] = 0;
        for(int transInd=0; transInd <5; transInd++){
            if(transInd%2 == 0)
                curr[transInd] = max( (-prices[i]+ prev[transInd+1]) ,prev[transInd] );
            else
                curr[transInd] =  max( (prices[i]+ prev[transInd+1]) , prev[transInd] );

        }
        prev = curr;
    }
    return prev[0];
}



int maxProfit(vector<int>& prices)
{
    
    int n = prices.size();
    int transInd = 0;
    
    return solveRec(0,prices,n,transInd);

    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solveMem(0,prices,n,transInd,dp);

    return solveTab(prices,n);

    return solveSpaceOpt(prices,n);
    
}
