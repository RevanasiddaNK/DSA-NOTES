#include <bits/stdc++.h>
#include<limits.h>

int solveRec(int index, int wt, vector<int>&weight, vector<int>&value){
    // base case
    if(index == 0){
        if(weight[0] <= wt)
            return value[0];
        else
            return 0;
    }

    // explore all paths
    int notsteal = 0+solveRec(index-1,wt,weight,value);
    int steal = INT_MIN;
    if(weight[index] <= wt)
        steal = value[index]+solveRec(index-1,wt-weight[index],weight,value);
    
    return max(steal,notsteal);

}

int solveMem(int index, int wt, vector<int>&weight, vector<int>&value, vector<vector<int>>&dp){
    // base case
    if(index == 0){
        if(weight[0] <= wt)
            return value[0];
        else
            return 0;
    }

    if(dp[index][wt] != -1)
        return dp[index][wt];

    // explore all paths
    int notsteal = 0+solveMem(index-1,wt,weight,value,dp);
    int steal = INT_MIN;
    if(weight[index] <= wt)
        steal = value[index]+solveMem(index-1,wt-weight[index],weight,value,dp);
    
    return dp[index][wt] = max(steal,notsteal);

}

int solveTab(vector<int>weight, vector<int>value, int n, int maxWeight){
    vector<vector<int>>dp(n, vector<int>(maxWeight+1, 0));

    // base case
    for(int wt=0; wt<= maxWeight; wt++){
        if(weight[0] <= wt)
            dp[0][wt] = value[0];
        else
            dp[0][wt] = 0;
    }

    for(int index=1; index<n; index++){
        for(int wt=0; wt<=maxWeight; wt++){
            int notsteal = 0+dp[index-1][wt];
            int steal = INT_MIN;
            if(weight[index] <= wt)
                steal = value[index]+dp[index-1][wt-weight[index]];
    
            dp[index][wt] = max(steal,notsteal);
        }
    }
    return dp[n-1][maxWeight];
}

int solveSpaceOpt(vector<int>weight, vector<int>value, int n, int maxWeight){
    vector<int>prev(maxWeight+1,0);
    // base case
    for(int wt=0; wt<= maxWeight; wt++){
        if(weight[0] <= wt)
            prev[wt] = value[0];
        else
            prev[wt] = 0;
    }

    for(int index=1; index<n; index++){
        vector<int>curr(maxWeight+1,0);
        for(int wt=0; wt<=maxWeight; wt++){
            int notsteal = 0+prev[wt];
            int steal = INT_MIN;
            if(weight[index] <= wt)
                steal = value[index]+prev[wt-weight[index]];
    
            curr[wt] = max(steal,notsteal);
        }
        prev = curr;
    }
    return prev[maxWeight];
}



int knapsack(vector<int>weight, vector<int>value, int n, int maxWeight) 
{
	//return solveRec(n-1,maxWeight,weight,value);
    vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
    return solveMem(n-1,maxWeight,weight,value,dp);
    return solveTab(weight,value,n,maxWeight);
    return solveSpaceOpt(weight,value,n,maxWeight);
}
