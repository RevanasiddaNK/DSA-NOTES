#include <bits/stdc++.h>
#include<limits.h>
#include<vector>

int solveRec(vector<int>&heights, int n){

    if(n == 0)
       return 0;
    
    int onestep = solveRec(heights,n-1) + abs(heights[n]-heights[n-1]);
    int twosteps = INT_MAX;

    if(n > 1) 
        twosteps = solveRec(heights,n-2) + abs(heights[n]-heights[n-2]);

    return min(onestep, twosteps);
}

int solveMem(vector<int>&heights,int n,vector<int>&dp ){

    if(n == 0)
       return 0;

    if(dp[n] != -1)
        return dp[n];
    
    int onestep = solveMem(heights,n-1,dp) + abs(heights[n]-heights[n-1]);
    int twosteps = INT_MAX;

    if(n > 1) 
        twosteps = solveMem(heights,n-2,dp) + abs(heights[n]-heights[n-2]);

    return dp[n] = min(onestep, twosteps);
}

int solveTab(int n,vector<int>&heights){
    vector<int>dp(n,-1);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int onestep = dp[i-1]+abs(heights[i]-heights[i-1]);
        int twosteps = INT_MAX;
        if(i > 1)
            twosteps = dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i] = min(onestep,twosteps);
    }
    return dp[n-1];
}

int solveSpaceOpt(int n,vector<int>&heights){

    int prev2 = INT_MAX;
    int prev1 = 0;

    for (int i = 1; i < n; i++) {
        int onestep = prev1 + abs(heights[i] - heights[i - 1]);
        int twosteps = INT_MAX;
        if (i > 1)
            twosteps = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(onestep, twosteps);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int frogJump(int n, vector<int>&heights)
{
    int ans = -1;
    // ZERO Based indexing is there
 //   ans = solveRec(heights,n-1);
    
    vector<int>dp(n,-1);
  //  ans = solveMem(heights,n-1,dp);
    
  //  ans = solveTab(n,heights);

    ans = solveSpaceOpt(n,heights);

    return ans;
}
