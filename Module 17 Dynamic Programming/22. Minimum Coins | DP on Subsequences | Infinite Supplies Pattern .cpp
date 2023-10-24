#include <bits/stdc++.h> 
#include<limits.h>

int solveRec(int amount,vector<int> &num){
    if(amount == 0)
        return 0;
        
    if(amount < 0)
        return INT_MAX;
    
    int ans = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int mini = solveRec(amount-num[i],num);
        if(mini != INT_MAX)
            ans = min(ans,mini+1);
    }
    return ans;
}

int solveMem(int amount,vector<int> &num, vector<int>&dp){
    if(amount == 0)
        return 0;
        
    if(amount < 0)
        return INT_MAX;
    
    if(dp[amount] != -1)
        return dp[amount];
    
    int ans = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int mini = solveMem(amount-num[i],num,dp);
        if(mini != INT_MAX)
            ans = min(ans,mini+1);
    }
    return dp[amount] = ans;
}

int solveTab(vector<int> &num, int x){
    vector<int>dp(x+1,0);
    dp[0] = 0;
    
    for(int amount = 1; amount<= x; amount++){
        int ans = INT_MAX;
        for(int i=0; i<num.size(); i++){
            int mini = INT_MAX;
            
            if( 0 <= amount-num[i])
                mini = dp[amount-num[i]];
            if(mini != INT_MAX)    
                ans = min(ans,mini+1);
        }
        dp[amount] = ans;
    }
    return dp[x];
}


int minimumElements(vector<int> &num, int x)
{
   int ans = -1;
    //ans = solveRec(x,num);
    vector<int>dp(x+1,-1);
    //ans = solveMem(x,num,dp);
    ans = solveTab(num,x);
    if(ans == INT_MAX)
        return -1;
    else 
        return ans;
 
}
