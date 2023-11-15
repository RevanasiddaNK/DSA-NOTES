#include<bits/stdc++.h>
long solveRec(long *values, bool buy, int i,int n){

    if(i == n)
        return 0;

    int unpick = solveRec(values,buy,i+1,n);
    int pick = solveRec(values,!buy,i+1,n);

    if(buy)
        pick = pick - values[i];
    else
        pick = pick + values[i];

    return max(pick,unpick);
    
}

long long solveMem(long *values, int buy, int i,int n,vector<vector<long long>>&dp){

    if(i == n)
        return 0;

    if(dp[i][buy] != -1)
        return dp[i][buy];

    long long profit = 0;

    if(buy == 1){
        long long pick = -values[i] + solveMem(values,0,i+1,n,dp);
        long long unpick = solveMem(values,1,i+1,n,dp);
        profit =  max(pick,unpick);
    }
    else{
        long long pick = values[i] + solveMem(values,1,i+1,n,dp);
        long long unpick = solveMem(values,0,i+1,n,dp);
        profit =  max(pick,unpick);
    }
    return dp[i][buy] = profit; 
}


long long solveTab(long *values, int n){
    vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
    for(int b=0; b<2; b++)
        dp[n][b] = 0;

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            long long profit= 0;
            if(buy == 1){
                long long pick = -values[i] + dp[i+1][0];
                long long unpick = dp[i+1][1];
                profit =  max(pick,unpick);
            }
            else{
                long long pick = values[i] + dp[i+1][1];
                long long unpick = dp[i+1][0];
                profit =  max(pick,unpick);
            }
            dp[i][buy] = profit;

        }
    }
    return dp[0][1];
}

long long solveSpaceOpt(long *values, int n){
    vector<long long>prev(2,-1);
    for(int b=0; b<2; b++)
        prev[b] = 0;

    for(int i=n-1; i>=0; i--){
        vector<long long>curr(2,-1);
        for(int buy=0; buy<2; buy++){
            long long profit= 0;
            if(buy == 1){
                long long pick = -values[i] + prev[0];
                long long unpick = prev[1];
                profit =  max(pick,unpick);
            }
            else{
                long long pick = values[i] + prev[1];
                long long unpick = prev[0];
                profit =  max(pick,unpick);
            }
           curr[buy] = profit;
        }
        prev = curr;
    }
    return prev[1];
}

long long solveSpaceOpt2(long *values, int n){
    
    long long prevbuy = 0;
    long long prevnotbuy = 0;

    for(int i=n-1; i>=0; i--){
        long long currbuy = -1;
        long long currnotbuy = -1;
        for(int buy=0; buy<2; buy++){
            long long profit= 0;
            if(buy == 1){
                long long pick = -values[i] + prevnotbuy;
                long long unpick = prevbuy;
                currbuy =  max(pick,unpick);
            }
            else{
                long long pick = values[i] + prevbuy;
                long long unpick = prevnotbuy;
                currnotbuy =  max(pick,unpick);
            }
        }
        prevbuy = currbuy;
        prevnotbuy = currnotbuy;
    }
    return prevbuy;
}





long getMaximumProfit(long *values, int n)
{
    int buy = 1;
    return solveRec(values,buy,0,n);

    vector<vector<long long>>dp(n,vector<long long>(2,-1));   
    return solveMem(values,buy,0,n,dp);

    return solveTab(values,n);

    return solveSpaceOpt(values,n);

    return solveSpaceOpt2(values,n);

}
