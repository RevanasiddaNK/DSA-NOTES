#include <bits/stdc++.h> 
int modulo = 1e9+7;


int solveRecursion(int index, int sum, vector<int>&arr){
//step 1
    if(index == 0){
        if(sum == 0 && arr[0] == 0)
            return 2;
        else if(sum == 0 || sum == arr[0])
            return 1;
        else
            return 0;
    }
//step 2    
    int nottake = solveRecursion(index-1,sum,arr);
    int take = 0;
    if(arr[index] <= sum)
        take = solveRecursion(index-1,sum-arr[index],arr);
// step 3   
    return (nottake+take)%modulo;

}

int solveMemoization(int index, int sum, vector<int>&arr,vector<vector<int>>&dp){
//step 1
    if(index == 0){
        if(sum == 0 && arr[0] == 0)
            return 2;
        else if(sum == 0 || sum == arr[0])
            return 1;
        else
            return 0;
    }
    if(dp[index][sum] != -1)
        return dp[index][sum];
//step 2    
    int nottake = solveMemoization(index-1, sum, arr, dp);
    int take = 0;
    if(arr[index] <= sum)
        take = solveMemoization(index-1, sum-arr[index], arr, dp);
// step 3   
    return dp[index][sum] = (nottake+take)%modulo;

}

int solveTabulation(vector<int>&arr, int n, int target){
//step 1
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int i=0; i<=target; i++){
        if(i == 0 && arr[0] == 0)
            dp[0][0] = 2;
        else if(arr[0] == i || i == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
//step 2
    for(int i=1; i<n; i++){
        for(int sum=0; sum<=target; sum++){
            //step 3
            int nottake = dp[i-1][sum];
            int take = 0;
            if(arr[i] <= sum)
                take = dp[i-1][sum-arr[i]];

            dp[i][sum] = (nottake+take)%modulo;
        }
    }
    return dp[n-1][target];
}

int solveSpaceOpt(vector<int>&arr, int n, int target){
//step 1
    vector<int>prev(target+1,0);
    for(int i=0; i<=target; i++){
        if(i == 0 && arr[0] == 0)
            prev[0] = 2;
        else if(arr[0] == i || i == 0)
            prev[i] = 1;
        else
            prev[i] = 0;
    }
//step 2
    for(int i=1; i<n; i++){
        vector<int>curr(target+1,0);
        for(int sum=0; sum<=target; sum++){
            //step 3
            int nottake = prev[sum];
            int take = 0;
            if(arr[i] <= sum)
                take = prev[sum-arr[i]];

            curr[sum] = (nottake+take)%modulo;
        }
        prev = curr;
    }
    return prev[target];
}


int countPartitions(int n, int d, vector<int>&arr) {

    int sum = 0;
    for(int i:arr)
        sum += i;

// Edge Case
    if(sum-d < 0 || (sum-d)&1)
        return 0;

    int target = (sum-d)/2;

/*
this is also correct
    if(sum+d < 0 || (sum+d)&1)
        return 0;

    int target = (sum+d)/2;
*/
    return solveRecursion(n-1,target,arr);

    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return solveMemoization(n-1,target,arr,dp);
    return solveTabulation(arr,n,target);
    return solveSpaceOpt(arr,n,target);
}


