#include<limits.h>

int solveRec(int index, int w, vector<int> &weight, vector<int> &profit){
//Base Case
    if(index == 0){
        int n = w/weight[0];
        return profit[0]*n;
        //return ((int)(w/weight[0])) * profit[0];
    }
//Explore All paths

    int notpick = 0 + solveRec(index-1,w,weight,profit);
    int pick = INT_MIN;
    if(weight[index] <= w)
        pick =  profit[index] + solveRec(index,w-weight[index],weight,profit);

// return max of all paths
    return max(pick,notpick);
}

int solveMem(int index, int w, vector<int> &weight, vector<int> &profit,vector<vector<int>>&dp){
//Base Case
    if(index == 0){
        int n = w/weight[0];
        return profit[0]*n;
        //return ((int)(w/weight[0])) * profit[0];
    }

    if(dp[index][w] != -1)
        return dp[index][w];

//Explore All paths

    int notpick = 0 + solveMem(index-1,w,weight,profit,dp);
    int pick = INT_MIN;
    if(weight[index] <= w)
        pick =  profit[index] + solveMem(index,w-weight[index],weight,profit,dp);

// return max of all paths
    return dp[index][w] = max(pick,notpick);
}

int solveTab(int n, int wt, vector<int>&profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(wt+1,INT_MIN));
    // base case
    for(int w=0; w<=wt; w++ )
        dp[0][w] =  ((int)(w/weight[0])) * profit[0];
    
    for(int index=1; index<n; index++){
        for(int w=0; w<=wt; w++){
            int notpick = 0 + dp[index-1][w]; 
            int pick = INT_MIN;
            if(weight[index] <= w)
                pick =  profit[index] + dp[index][w-weight[index]]; 
            dp[index][w] = max(pick,notpick);
        }
    }
    return dp[n-1][wt];
}

int solveSpaceOpt(int n, int wt, vector<int>&profit, vector<int> &weight){
    vector<int>prev(wt+1,INT_MIN);
    // base case
    for(int w=0; w<=wt; w++ )
        prev[w] =  ((int)(w/weight[0])) * profit[0];
    
    for(int index=1; index<n; index++){
        vector<int>curr(wt+1,INT_MIN);
        for(int w=0; w<=wt; w++){
            int notpick = 0 + prev[w]; 
            int pick = INT_MIN;
            if(weight[index] <= w)
                pick =  profit[index] + curr[w-weight[index]]; 
            curr[w] = max(pick,notpick);
        }
        prev = curr;
    }
    return prev[wt];
}



int unboundedKnapsack(int n, int w, vector<int>&profit, vector<int> &weight){
    //return solveRec(n-1,w,weight,profit);
    
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    //return solveMem(n-1,w,weight,profit,dp);

    //return solveTab(n,w,profit,weight);

    return solveSpaceOpt(n,w,profit,weight);

}
