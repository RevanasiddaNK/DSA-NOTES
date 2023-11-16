#include<bits/stdc++.h>
int solveRec(vector<int>&values, int buy, int i,int n, int fee){

    if(i >= n)
        return 0;

    int profit = 0;

    if(buy == 1){
        int pick = -values[i] + solveRec(values,0,i+1,n,fee)-fee;
        int unpick = solveRec(values,1,i+1,n,fee);
        profit =  max(pick,unpick);
    }
    else{
        int pick = values[i] + solveRec(values,1,i+1,n,fee);
        int unpick = solveRec(values,0,i+1,n,fee);
        profit =  max(pick,unpick);
    }
    return profit;
}


int solveMem(vector<int>&values, int buy, int i,int n,vector<vector<int>>&dp, int fee){

    if(i >= n)
        return 0;

    if(dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;

    if(buy == 1){
        int pick = -values[i] + solveMem(values,0,i+1,n,dp,fee)-fee;
        int unpick = solveMem(values,1,i+1,n,dp,fee);
        profit =  max(pick,unpick);
    }
    else{
        int pick = values[i] + solveMem(values,1,i+1,n,dp,fee);
        int unpick = solveMem(values,0,i+1,n,dp,fee);
        profit =  max(pick,unpick);
    }
    return dp[i][buy] = profit; 
}


int solveTab(vector<int>&values, int n, int fee){
    vector<vector<int>>dp(n+2,vector<int>(2,-1));
    for(int b=0; b<2; b++){
        dp[n][b] = 0;
    }

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            int profit= 0;
            if(buy == 1){
                int pick = -values[i] + dp[i+1][0] - fee;
                int unpick = dp[i+1][1];
                profit =  max(pick,unpick);
            }
            else{
                int pick = values[i] + dp[i+1][1];
                int unpick = dp[i+1][0];
                profit =  max(pick,unpick);
            }
            dp[i][buy] = profit;

        }
    }
    return dp[0][1];
}

int solveSpaceOpt(vector<int>&values, int n,int fee){
    vector<int>prev(2,-1);
    for(int b=0; b<2; b++)
        prev[b] = 0;

    for(int i=n-1; i>=0; i--){
        vector<int>curr(2,-1);
        for(int buy=0; buy<2; buy++){
            long long profit= 0;
            if(buy == 1){
                int pick = -values[i] + prev[0] - fee;
                int unpick = prev[1];
                profit =  max(pick,unpick);
            }
            else{
                int pick = values[i] + prev[1];
                int unpick = prev[0];
                profit =  max(pick,unpick);
            }
           curr[buy] = profit;
        }
        prev = curr;
    }
    return prev[1];
}

int maximumProfit(vector<int> &prices, int n, int fee)
{
	//return solveRec(prices,1,0,n,fee);

    vector<vector<int>>dp(n,vector<int>(2,-1));   
    //return solveMem(prices,1,0,n,dp,fee);

    //return solveTab(prices,n,fee);

    return solveSpaceOpt(prices,n,fee);
}
