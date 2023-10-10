#include <bits/stdc++.h> 

// Recursion
long long int solveRec(vector<int>&nums,int n){
    if(n < 0)
        return 0;
    
    long long int  pick = solveRec(nums,n-2)+nums[n];
    long long int  notpick = solveRec(nums,n-1)+0;

    return max(pick,notpick);
}

// Memoization
long long int  solveMem(vector<int> &nums, int n,vector<long long int >&dp){
    if(n < 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];
    
    long long int  pick = solveMem(nums,n-2,dp)+nums[n];
    long long int notpick = solveMem(nums,n-1,dp)+0;

    return dp[n] = max(pick,notpick);
}

// Tabulation
long long int solveTab(vector<int>&nums){
    long long int n = nums.size();
    vector<long long int>dp(n+1,-1); 
    dp[0] = nums[0];
    for(long long int i=1; i<n; i++){
        long long int pick = nums[i];
        // Edge Case
        if(i != 1)
            pick += dp[i-2];

        long long int notpick = 0+dp[i-1];

        dp[i] = max(pick,notpick);
    }
    return dp[n-1];
}

// Space Optimized Approach
long long int  solveSpaceOpt(vector<int>&nums){
    int n = nums.size();
    long long int  prev2 = 0;          // nums[-1] case negative index
    long long int  prev1 = nums[0];    // dp[0] = nums[0];
    for(long long int i=1; i<n; i++){
        long long int pick = nums[i]+prev2;
        long long int notpick = 0+prev1;
        // dp[i] = max(pick,notpick); curr
        long long int  curr = max(pick, notpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1)
        return valueInHouse[0];

/*    // Recursion
    long long int ans1 = solveRec(valueInHouse,n-2);  
    // first index included and last index not
    valueInHouse[0] = INT_MIN;
    long long int ans2 = solveRec(valueInHouse,n-1);
    // first index not included, last index included
*/

/*      // Memoization
    vector<long long int>dp1(n+1,-1);
    long long int ans1 = solveMem(valueInHouse,n-2,dp1); 
    valueInHouse[0] = INT_MIN;
    vector<long long int>dp2(n+1,-1);
    long long int ans2 = solveMem(valueInHouse,n-1,dp2); 
*/

    vector<int>valueInHouse1(n-1);
    for(int i=0; i<n-1; i++)
        valueInHouse1[i] = valueInHouse[i];

    vector<int>valueInHouse2(n-1);
    for(int i=0; i<n-1; i++)
        valueInHouse2[i] = valueInHouse[i+1];
     
/*  // Tabulation
    long long int ans1 = solveTab(valueInHouse1);
    long long int ans2 = solveTab(valueInHouse2);
*/
    // Space Optimization
    long long int ans1 = solveSpaceOpt(valueInHouse1);
    long long int ans2 = solveSpaceOpt(valueInHouse2);   


    return max(ans1,ans2);
}
