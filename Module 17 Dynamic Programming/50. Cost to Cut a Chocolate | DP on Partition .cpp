#include <bits/stdc++.h> 

int solveRec(int i, int j, vector<int>&cuts){

    if(i>j)
        return 0;
    
    int mini = 1e9;
    for(int k=i; k<=j; k++){
        int cost = cuts[j+1] - cuts[i-1] + solveRec(i,k-1,cuts) + solveRec(k+1,j,cuts);
        mini = min(mini,cost);
    }
    return mini;
}

int solveMem(int i, int j, vector<int>&cuts,vector<vector<int>>&dp){

    if(i>j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int mini = 1e9;
    for(int k=i; k<=j; k++){
        int cost = cuts[j+1] - cuts[i-1] + solveMem(i,k-1,cuts,dp) + solveMem(k+1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}

int solveTab(int c, vector<int>&cuts){

    // Base Case
    vector<vector<int>>dp(c+2,vector<int>(c+2,0));

    for(int i=c; i>=1; i--){
        for(int j=1; j<=c; j++){

            if(i>j){
                dp[i][j] = 0;
                continue;
            }

            int mini = INT_MAX;
            for(int k=i; k<=j; k++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

int cost(int n, int c, vector<int>&cuts){
    
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());

    return solveRec(1,c,cuts);

    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    return solveMem(1,c,cuts,dp);
    
    return solveTab(c,cuts);
}
