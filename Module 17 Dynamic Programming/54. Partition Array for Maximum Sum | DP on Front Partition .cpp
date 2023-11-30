#include<bits/stdc++.h>

int solveRec(int i,vector<int> &arr, int k, int n){

    if(i == n)
        return 0;

    int maxAns = -1e9, maxi = -1e9,len = 0;
    for(int j=i; j<min(n,i+k); j++){
        len++;
        maxi = max(maxi,arr[j]);
        int partSum = len*maxi + solveRec(j+1,arr,k,n);
        maxAns = max(maxAns,partSum);
    }
    return maxAns;
}

int solveMem(int i,vector<int> &arr, int k, int n,vector<int>&dp){

    if(i == n)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int maxAns = -1e9, maxi = -1e9,len = 0;
    for(int j=i; j<min(n,i+k); j++){
        len++;
        maxi = max(maxi,arr[j]);
        int partSum = len*maxi + solveMem(j+1,arr,k,n,dp);
        maxAns = max(maxAns,partSum);
    }
    return dp[i] = maxAns;
}

int solveTab(vector<int> &arr, int k, int n){

    vector<int>dp(n+1,-1);
    dp[n] = 0;

    for(int i=n-1; i>=0; i--){

        int maxAns = -1e9, maxi = -1e9,len = 0;
        for(int j=i; j<min(n,i+k); j++){
            len++;
            maxi = max(maxi,arr[j]);
            int partSum = len*maxi + dp[j+1];
            maxAns = max(maxAns,partSum);
        }
        dp[i] = maxAns;
        
    }

    return dp[0];
}


int maximumSubarray(vector<int> &arr, int k){
   
   int n = arr.size();
   return solveRec(0,arr,k,n);

   vector<int>dp(n,-1);
   return solveMem(0,arr,k,n,dp);

   return solveTab(arr,k,n);
}
