#include <bits/stdc++.h> 

bool solveRec(int index, int target, vector<int> &arr){
    
    if(target == 0)
        return true;
    
    if(index == 0){
        /*
        if(target == arr[0])
            return true;
        else
            return false;
        */
        return target == arr[index];
    }
    
    bool nottake = solveRec(index-1,target,arr);  
    if(nottake)
        return true;
    
    // if positive numbers in arr 
    bool take = false;
    if(target >= arr[index])
        take = solveRec(index-1,target-arr[index],arr);
        
    return take; 
}


bool solveMem(int index, int target, vector<int> &arr,vector<vector<int>>&dp){
    
    if(target == 0)
        return true;
    
    if(index == 0)
        return target == arr[index];

    if(dp[index][target] != -1)
        return dp[index][target];
    
    bool nottake = solveMem(index-1,target,arr,dp);
    
    // if positive numbers in arr 
    bool take = false;
    if(target >= arr[index])
        take = solveMem(index-1,target-arr[index],arr,dp);
    
    return dp[index][target] = take || nottake; 
      
}

bool solveTab(int n, int k, vector<int> &arr){
    vector<vector<int>>dp(n, vector<int>(k+1,0));

    for(int i=0; i<n; i++)
        dp[i][0] = 1;
    
    if(arr[0] <= k)
        dp[0][arr[0]] = 1;

    for(int index = 1; index<n; index++){
        for(int target = 1; target <= k; target++){
            bool nottake = dp[index-1][target];
            bool take = false;
            if(target >= arr[index])
                take = dp[index-1][target-arr[index]];
    
            dp[index][target] = take || nottake; 
        }
    }
    return dp[n-1][k];
}

bool solveSpaceOpt(int n, int k, vector<int>&arr){
    
    vector<bool> prev(k+1,0);

    if(arr[0] <= k)
        prev[arr[0]] = 1;

    for(int index = 1; index<n; index++){
        vector<bool>curr(k+1,0);
        for(int target = 1; target <= k; target++){
            prev[0] = true;
            curr[0] = true;
            bool nottake = prev[target];
            bool take = false;
            if(target >= arr[index])
                take = prev[target-arr[index]];
    
            curr[target] = take || nottake; 
        }
        prev = curr;
    }
    return prev[k];
}

bool subsetSumToK(int n, int target, vector<int> &arr) {
   
//    return solveRec(n-1,target,arr);
    vector<vector<int>>dp(n, vector<int>(target+1,-1));
    return solveMem(n-1,target,arr,dp);

    return solveTab(n,target,arr);

    return solveSpaceOpt(n,target,arr);

}
