#include<limits.h>

int solveRec(int n, int k, vector<int> &height){
    if(n == 0)
        return 0;
    
    int minSteps = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n - i >= 0) {
          int temp = solveRec(n-i, k, height)+abs(height[n]-height[n-i]);
          minSteps = min(minSteps,temp);
        }
    }
    return minSteps;
}

int solveMem(int n, int k, vector<int> &height,vector<int>&dp){
    
    if(n == 0)
        return 0;
        
    if(dp[n] != -1)
        return dp[n];
        
    int minSteps = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n - i >= 0) {
          int temp = solveMem(n-i, k, height,dp)+abs(height[n]-height[n-i]);
          minSteps = min(minSteps,temp);
        }
    }   
    return dp[n] = minSteps;
}

int solveTab(int n, int k, vector<int> &height){
    vector<int>dp(n+1,-1);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i - j >= 0) {
                int temp = solveMem(i-j, k, height,dp)+abs(height[i]-height[i-j]);
                minSteps = min(minSteps,temp);
            }
        }
        dp[i] = minSteps;
    } 
    return dp[n-1];              
}

int minimizeCost(int n, int k, vector<int> &height){
    
    int ans = -1;
//    ans = solveRec(n-1,k,height);

    vector<int>dp(n,-1);
//    ans = solveMem(n-1,k,height,dp);

    ans = solveTab(n,k,height);

    return ans;
}
