#include <bits/stdc++.h> 

// Recursion
int solveRec(vector<int> &nums, int n){
    if(n < 0)
        return 0;
    
    int pick = solveRec(nums,n-2)+nums[n];
    int notpick = solveRec(nums,n-1)+0;

    return max(pick,notpick);
}

// Memoization
int solveMem(vector<int> &nums, int n,vector<int>&dp){
    if(n < 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];
    
    int pick = solveMem(nums,n-2,dp)+nums[n];
    int notpick = solveMem(nums,n-1,dp)+0;

    return dp[n] = max(pick,notpick);
}

// Tabulation
int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n+1,-1); 
    dp[0] = nums[0];
    for(int i=1; i<n; i++){

        int pick = nums[i];
        // Edge Case
        if(i != 1)
            pick += dp[i-2];

        int notpick = 0+dp[i-1];

        dp[i] = max(pick,notpick);
    }
    return dp[n-1];
}

// Space Optimized Approach
int solveSpaceOpt(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;          // nums[-1] case negative index
    int prev1 = nums[0];    // dp[0] = nums[0];
    for(int i=1; i<n; i++){
        int pick = nums[i]+prev2;
        int notpick = 0+prev1;
        // dp[i] = max(pick,notpick); curr
        int curr = max(pick, notpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


int maximumNonAdjacentSum(vector<int> &nums){
    int ans;
    int n = nums.size();
//    ans = solveRec(nums,n-1);

    vector<int>dp(n+1,-1);
    
//    ans = solveMem(nums,n-1,dp);
//    ans = solveTab(nums);
    ans = solveSpaceOpt(nums);
 
    return ans;
}
