#include<bits/stdc++.h>
int solveRec(vector<int>&values, int buy, int i,int n){

    if(i >= n)
        return 0;

    int profit = 0;

    if(buy == 1){
        int pick = -values[i] + solveRec(values,0,i+1,n);
        int unpick = solveRec(values,1,i+1,n);
        profit =  max(pick,unpick);
    }
    else{
        int pick = values[i] + solveRec(values,1,i+2,n);
        int unpick = solveRec(values,0,i+1,n);
        profit =  max(pick,unpick);
    }
    return profit; 
    
}


int solveMem(vector<int>&values, int buy, int i,int n,vector<vector<int>>&dp){

    if(i >= n)
        return 0;

    if(dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;

    if(buy == 1){
        int pick = -values[i] + solveMem(values,0,i+1,n,dp);
        int unpick = solveMem(values,1,i+1,n,dp);
        profit =  max(pick,unpick);
    }
    else{
        int pick = values[i] + solveMem(values,1,i+2,n,dp);
        int unpick = solveMem(values,0,i+1,n,dp);
        profit =  max(pick,unpick);
    }
    return dp[i][buy] = profit; 
}


int solveTab(vector<int>&values, int n){
    vector<vector<int>>dp(n+2,vector<int>(2,-1));
    for(int b=0; b<2; b++){
        dp[n][b] = 0;
        dp[n+1][b] = 0;
    }

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            int profit= 0;
            if(buy == 1){
                int pick = -values[i] + dp[i+1][0];
                int unpick = dp[i+1][1];
                profit =  max(pick,unpick);
            }
            else{
                int pick = values[i] + dp[i+2][1];
                int unpick = dp[i+1][0];
                profit =  max(pick,unpick);
            }
            dp[i][buy] = profit;

        }
    }
    return dp[0][1];
}


int solveSpaceOpt(vector<int>&values, int n){

    vector<int>curr(2,-1);
    vector<int>front1(2,-1);
    vector<int>front2(2,-1);

    for(int b=0; b<2; b++){
        curr[b] = 0;
        front2[b] = 0;
        front1[b] = 0;
    }

    for(int i=n-1; i>=0; i--){
        
            int pick = -values[i] + front1[0];
            int unpick = front1[1];
            curr[1] =  max(pick,unpick);
            
            pick = values[i] + front2[1];
            unpick = front1[0];
            curr[0] =  max(pick,unpick);
        
            front2 = front1;
            front1 = curr;               
    }
    return curr[1];
}



int stockProfit(vector<int>&prices){
    int buy = 1;
    int n = prices.size();
    return solveRec(prices,buy,0,n);

    vector<vector<int>>dp(n,vector<int>(2,-1));   
    return solveMem(prices,buy,0,n,dp);

    return solveTab(prices,n);

    return solveSpaceOpt(prices,n);

}
