#include <bits/stdc++.h> 

int solveRec(int i1, int i2,string &s1, string &s2){
    if(i1 < 0 || i2 < 0)
        return 0;
    
    if(s1[i1] == s2[i2])
        return 1+ solveRec(i1-1,i2-1,s1,s2);
    else{
        return max(solveRec(i1,i2-1,s1,s2),solveRec(i1-1,i2,s1,s2));
    }
}

int solveMem(int i1, int i2,string &s1, string &s2,vector<vector<int>>&dp){
    if(i1 == 0 || i2 == 0)
        return 0;
    
    if(dp[i1][i2] != -1)
        return dp[i1][i2];

    if(s1[i1-1] == s2[i2-1])
        return dp[i1][i2] = 1+ solveMem(i1-1,i2-1,s1,s2,dp);
    else{
        return dp[i1][i2] = max(solveMem(i1,i2-1,s1,s2,dp),solveMem(i1-1,i2,s1,s2,dp));
    }
}

// Tabulation
int solveTab(int m, int n, string s1, string s2){
    vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MIN));
// Base cases after shifting of indexes right by +1
    for(int i=0; i<=n; i++)
        dp[0][i] = 0;
    
    for(int i=0; i<=m; i++)
        dp[i][0] = 0;
    
// changing paramenters to nested loops
    for(int i1=1; i1<=m; i1++){
        for(int i2=1; i2<=n; i2++){
            if(s1[i1-1] == s2[i2-1]){
                dp[i1][i2] = 1 + dp[i1-1][i2-1]; 
            }
            else{
                dp[i1][i2] = 0 + max(dp[i1-1][i2], dp[i1][i2-1]); 
            }
        }
    }
    return dp[m][n];
}

// Tabulation
int spaceOpt(int m, int n, string s1, string s2){

    vector<int>prev(n+1,INT_MIN);
// Base cases after shifting of indexes right by +1
    for(int i=0; i<=n; i++)
        prev[i] = 0;
    
// changing paramenters to nested loops
    for(int i1=1; i1<=m; i1++){
        vector<int>curr(n+1,INT_MIN);
        curr[0]  = 0;
        for(int i2=1; i2<=n; i2++){
            if(s1[i1-1] == s2[i2-1]){
                curr[i2] = 1 + prev[i2-1]; 
            }
            else{
                curr[i2] = 0 + max(prev[i2], curr[i2-1]); 
            }
        }
        prev = curr;
    }
    return prev[n];
}


int LongestCommonSubsequence(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    //return solveRec(m-1,n-1,s1,s2);

    vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
   return solveMem(m,n,s1,s2,dp);

   return solveTab(m,n,s1,s2);

   return spaceOpt(m,n,s1,s2);

}

int longestPalindromeSubsequence(string s)
{
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return LongestCommonSubsequence(s1,s2);
}
