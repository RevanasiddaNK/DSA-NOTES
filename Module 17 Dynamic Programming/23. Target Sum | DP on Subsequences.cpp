#include <bits/stdc++.h> 

int solveRec0(int index, int target, vector<int>&arr){
// any one base case is required to run a code
// base case 1

    if(index == 0){

        if(target - arr[0] == 0 && target+arr[0] == 0)
            return 2;
        else if(target - arr[0] == 0 || target+arr[0] == 0)
            return 1;
        else
            return 0;
    }
    
    if(index < 0)
        return target == 0;

    int plus = solveRec0(index-1,target+arr[index],arr);
    int minus = solveRec0(index-1,target-arr[index],arr);

    return plus+minus;
}

// target can be negative also 


int solveRecursion(int index, int sum, vector<int>&arr){

    // base case
    if(index == 0){
        if(sum == 0 && arr[0] == 0)
            return 2;
        else if(sum == arr[0] || sum == 0 )
            return 1;
        else
            return 0;
    }

    int notpick = solveRecursion(index-1, sum,arr);
    int pick = 0;
    if(arr[index] <= sum){
        pick = solveRecursion(index-1, sum-arr[index],arr);
    }
    return pick+notpick;
}

int solveMem(int index, int sum, vector<int>&arr, vector<vector<int>>&dp){

    // base case
    if(index == 0){
        if(sum == 0 && arr[0] == 0)
            return 2;
        else if(sum == arr[0] || sum == 0 )
            return 1;
        else
            return 0;
    }

    if(dp[index][sum] != -1)
        return dp[index][sum];

    int notpick = solveMem(index-1, sum,arr,dp);
    int pick = 0;
    if(arr[index] <= sum){
        pick = solveMem(index-1, sum-arr[index],arr,dp);
    }
    return dp[index][sum] = pick+notpick;
}

int solveTab(int n, int target, vector<int>&arr){
    
    vector<vector<int>>dp(n, vector<int>(target+1, 0));
// Base Case
    for(int sum=0; sum <= target; sum++){
        if(sum == 0 && arr[0] == 0)
            dp[0][0] = 2;
        else if(sum == arr[0] || sum == 0 )
            dp[0][sum] = 1;
        else
            dp[0][sum] = 0;
    }

    for(int index=1; index<n; index++){
        for(int sum=0; sum<=target; sum++){
            int notpick = dp[index-1][sum];
            int pick = 0;
            if(arr[index] <= sum){
                pick = dp[index-1][sum-arr[index]];
            }
            dp[index][sum] = pick+notpick;
        }
    }
    return dp[n-1][target];
}

int solveSpaceOpt(int n, int target, vector<int>&arr){
    
    vector<int>prev(target+1, 0);
// Base Case
    for(int sum=0; sum <= target; sum++){
        if(sum == 0 && arr[0] == 0)
            prev[0] = 2;
        else if(sum == arr[0] || sum == 0 )
            prev[sum] = 1;
        else
            prev[sum] = 0;
    }

    for(int index=1; index<n; index++){
        vector<int>curr(target+1, 0);
        for(int sum=0; sum<=target; sum++){
            int notpick = prev[sum];
            int pick = 0;
            if(arr[index] <= sum){
                pick = prev[sum-arr[index]];
            }
            curr[sum] = pick+notpick;
        }
        prev = curr;
    }
    return prev[target];
}



int subsetSumToDiff(int n, int target, vector<int>&arr){

    int totalsum = 0;
    for(int i: arr)
        totalsum += i;
    
    if((target+totalsum)&1 || target+totalsum < 0)
        return 0;

    int s1 = (target+totalsum)/2;

    //return solveRecursion(n-1,s1,arr);
    vector<vector<int>>dp(n, vector<int>(s1+1, -1));
    return solveMem(n-1,s1,arr,dp);
    return solveTab(n,s1,arr);
    return solveSpaceOpt(n,s1,arr);

}

int targetSum(int n, int target, vector<int>&arr) {

    // return solveRec0(n-1,target,arr);

    return subsetSumToDiff(n,target,arr);

}
