#include<bits/stdc++.h>

bool isPalin(string &str, int i, int j){
    while(i <= j){
        if(str[i++] != str[j--])
            return 0;
    }
    return 1;
}

int solveRec(int i, string str,int n){
    
    if(i >= n)
        return 0;

    int mini = INT_MAX;
    for(int j=i; j<n; j++){

        if(isPalin(str,i,j)){
            int numPart = 1 + solveRec(j+1,str,n);
            mini = min(mini,numPart);
        }
    }
    return mini;
}

int solveMem(int i, string str,int n, vector<int>&dp){
    
    if(i >= n)
        return 0;

    if( dp[i] != -1)
        return  dp[i];

    int mini = INT_MAX;
    for(int j=i; j<n; j++){

        if(isPalin(str,i,j)){
            int numPart = 1 + solveMem(j+1,str,n,dp);
            mini = min(mini,numPart);
        }
    }
    return dp[i] = mini;
}

int solveTab(string str, int n){
    
    vector<int>dp(n+1,-1);
    dp[n] = 0;

    for(int i=n-1; i>=0; i--){
        int mini = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalin(str,i,j)){
                int numPart = 1 + dp[j+1];
                mini = min(mini,numPart);
            }
        }
        dp[i] = mini;
    }
    return dp[0];
}


int palindromePartitioning(string str)
{
    int n = str.size();
    return solveRec(0,str,n)-1;

    vector<int>dp(n,-1);
    return solveMem(0,str,n,dp)-1;

    return solveTab(str,n)-1;
}
